#include "uart.h"

// ===================================================================
// GLOBAL VARIABLE DEFINITIONS (Matching uart.h declarations)
// ===================================================================
uart_fifo_t rx_fifo = {{0}, 0, 0, 0};
uart_stats_t uart_stats = {0, 0, 0, 0}; // Name matched to uart.h

// ===================================================================
// DIAGNOSTIC & TEST SUITE FUNCTION DEFINITIONS
// ===================================================================

/**
 * @brief Runs an interactive Echo test back to the host PC.
 */
void UART_Test_Echo(void) {
    unsigned int rx_word; // Changed to unsigned int for 16-bit FIFO
    unsigned char byte;
    
    UART_TxString("\r\n--- [TEST] Echo Loop Active (Send 5 characters from PC) ---\r\n");
    {
        unsigned char count = 0;
        while (count < 5) {
            if (FIFO_Get(&rx_word)) { // Pass pointer to 16-bit word
                byte = (unsigned char)(rx_word & 0x00FF); // Extract 8-bit payload
                
                UART_TxString("Received HEX: ");
                UART_TxHex(byte);
                UART_TxString(" | ASCII: '");
                UART_TxChar(byte);
                UART_TxString("'\r\n");
                count++;
            }
        }
    }
}

/**
 * @brief Tests baud rate re-initialization and SMOD toggle.
 */
void UART_Test_BaudRates(void) {
    UART_TxString("\r\n--- [TEST] Testing 9600 Baud Rate ---\r\n");
    UART_Init(9600, BAUD_NORMAL);
    UART_TxString("9600 Baud OK!\r\n");

    // delay(200); // Fixed function name

    UART_TxString("\r\n--- [TEST] Testing 19200 Baud Rate (SMOD = 1) ---\r\n");
    UART_Init(9600, BAUD_DOUBLE); // Double baud mode
    UART_TxString("19200 Baud OK!\r\n");

    // delay(200); // Fixed function name
    UART_Init(9600, BAUD_NORMAL); // Revert back to standard 9600
}

/**
 * @brief Prints current UART metrics and hardware error flags.
 */
void UART_PrintStats(void) {
    UART_TxString("\r\n================ UART METRICS ================\r\n");
    UART_TxString("TX Byte Count : ");
    UART_TxNumber(uart_stats.tx_count); // Fixed variable name
    UART_TxString("\r\nRX Byte Count : ");
    UART_TxNumber(uart_stats.rx_count); // Fixed variable name
    UART_TxString("\r\nFIFO Overflow : ");
    UART_TxString(rx_fifo.overflow ? "YES (Error)" : "NO (OK)");
    UART_TxString("\r\n=============================================\r\n");
}

// ===================================================================
// MAIN ROUTINE
// ===================================================================
void main(void) {
    // 1. MUST Initialize UART Hardware Peripheral First!
    UART_Init(9600, BAUD_NORMAL);
    
    // delay(100);

    // 2. Execute Diagnostics Sequences
    UART_TxString("\r\n=============================================\r\n");
    UART_TxString("  Nuvoton W78E052D UART Test Runner Started   \r\n");
    UART_TxString("=============================================\r\n");

    UART_Test_BaudRates();
    UART_Test_Echo();
    UART_PrintStats();

    // 3. Continuous Execution Loopback
    UART_TxString("\r\n[INFO] Test Suite Complete. Entering Loopback Mode...\r\n");
    while (1) {
        unsigned int rx_data;
        if (FIFO_Get(&rx_data)) {
            UART_TxChar((unsigned char)(rx_data & 0x00FF)); // Echo back byte
        }
    }
}