#include "uart.h"

// Instantiate Global Variables
uart_fifo_t rx_fifo;
uart_stats_t uart_stats;

// ===================================================================
// CORE UART DRIVER FUNCTION DEFINITIONS
// ===================================================================

/**
 * @brief Standard Initialization (Mode 1: 8-bit variable baud rate)
 */
void UART_Init(unsigned long baudrate, unsigned char double_baud) {
    UART_Init_Advanced(UART_MODE_1, baudrate, double_baud);
}

/**
 * @brief Advanced Initialization supporting all 4 UART Modes
 */
void UART_Init_Advanced(unsigned char mode, unsigned long baudrate, unsigned char double_baud) {
    unsigned char reload_val = 0;

    // Configure SMOD Bit in PCON
    if (double_baud) {
        PCON |= 0x80;  // SMOD = 1
        if (baudrate > 0) {
            reload_val = (unsigned char)(256 - (FREQ_OSC / (192UL * baudrate)));
        }
    } else {
        PCON &= ~0x80; // SMOD = 0
        if (baudrate > 0) {
            reload_val = (unsigned char)(256 - (FREQ_OSC / (384UL * baudrate)));
        }
    }

    // Configure Timer 1 only for Modes 1 and 3 (Variable Baud)
    if (mode == UART_MODE_1 || mode == UART_MODE_3) {
        TMOD &= 0x0F;
        TMOD |= 0x20; // Timer 1 Mode 2 (8-bit Auto-Reload)
        TH1 = reload_val;
        TL1 = reload_val;
        TR1 = 1;      // Start Timer 1
    }

    // Assign Hardware Serial Mode (SCON)
    SCON = mode;

    // Reset FIFO & Diagnostics
    FIFO_Init();
    uart_stats.rx_count = 0;
    uart_stats.tx_count = 0;

    ES = 1; // Enable Serial Interrupt
    EA = 1; // Enable Global Interrupts
}

/**
 * @brief Transmits a single character/byte over UART.
 */
void UART_TxChar(unsigned char ch) {
    SBUF = ch;
    while (!TI); // Wait for transmission complete flag
    TI = 0;      // Clear flag
    uart_stats.tx_count++;
}

/**
 * @brief Transmits a null-terminated string.
 */
void UART_TxString(const char *str) {
    while (*str) {
        UART_TxChar(*str++);
    }
}

/**
 * @brief Transmits an unsigned integer as ASCII text.
 */
void UART_TxNumber(unsigned int num) {
    char buf[6];
    int i = 0;

    if (num == 0) {
        UART_TxChar('0');
        return;
    }

    while (num > 0) {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i > 0) {
        UART_TxChar(buf[--i]);
    }
}

/**
 * @brief Transmits an 8-bit byte as Hexadecimal (0x00 - 0xFF).
 */
void UART_TxHex(unsigned char val) {
    unsigned char nibble;
    
    UART_TxString("0x");
    
    // High Nibble
    nibble = (val >> 4) & 0x0F;
    UART_TxChar(nibble < 10 ? (nibble + '0') : (nibble - 10 + 'A'));
    
    // Low Nibble
    nibble = val & 0x0F;
    UART_TxChar(nibble < 10 ? (nibble + '0') : (nibble - 10 + 'A'));
}

// ===================================================================
// 9-BIT MODE FUNCTION DEFINITIONS (Mode 2 & Mode 3)
// ===================================================================

/**
 * @brief Transmits 9-bit word (TB8 loaded from bit 8).
 */
void UART_Tx9Bit(unsigned int data_word) {
    TB8 = (data_word & 0x0100) ? 1 : 0; // Bit 8 assigned to TB8
    SBUF = (unsigned char)(data_word & 0x00FF);
    while (!TI);
    TI = 0;
    uart_stats.tx_count++;
}

/**
 * @brief Fetches 9-bit word from Software FIFO.
 */
int UART_Rx9Bit(unsigned int *data_word) {
    return FIFO_Get(data_word);
}

// ===================================================================
// SOFTWARE FIFO RING BUFFER FUNCTION DEFINITIONS
// ===================================================================

void FIFO_Init(void) {
    rx_fifo.head = 0;
    rx_fifo.tail = 0;
    rx_fifo.overflow = 0;
}

void FIFO_Put(unsigned int data_word) {
    unsigned char next = (rx_fifo.head + 1) % BUFFER_SIZE;
    if (next != rx_fifo.tail) {
        rx_fifo.buffer[rx_fifo.head] = data_word;
        rx_fifo.head = next;
    } else {
        rx_fifo.overflow = 1; // FIFO Full Error
    }
}

int FIFO_Get(unsigned int *data_word) {
    if (rx_fifo.head == rx_fifo.tail) {
        return 0; // Buffer Empty
    }
    *data_word = rx_fifo.buffer[rx_fifo.tail];
    rx_fifo.tail = (rx_fifo.tail + 1) % BUFFER_SIZE;
    return 1;
}

unsigned char FIFO_IsEmpty(void) {
    return (rx_fifo.head == rx_fifo.tail);
}

unsigned char FIFO_IsFull(void) {
    return (((rx_fifo.head + 1) % BUFFER_SIZE) == rx_fifo.tail);
}

// ===================================================================
// INTERRUPT SERVICE ROUTINE (ISR)
// ===================================================================

/**
 * @brief UART Interrupt Service Routine (Vector 4 / Address 0x0023)
 */
void UART_ISR(void) interrupt 4 {
    if (RI) {
        unsigned int rx_word;
        RI = 0; // Clear receive interrupt flag
        
        // Capture RB8 (Bit 8) and SBUF (Low Byte) atomically
        rx_word = ((unsigned int)RB8 << 8) | SBUF;
        
        FIFO_Put(rx_word);
        uart_stats.rx_count++;
    }
}