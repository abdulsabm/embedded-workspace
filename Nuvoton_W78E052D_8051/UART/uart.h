#ifndef __UART_H__
#define __UART_H__

#include "reg51.h"
#include "../include.h"

// ===================================================================
// SYSTEM CLOCK & HARDWARE CONFIGURATION
// ===================================================================
#ifndef FREQ_OSC
#define FREQ_OSC 11059200UL  // Oscillator Frequency in Hz (11.0592 MHz)
#endif

#define BUFFER_SIZE 16        // Power-of-2 size for Software FIFO

// ===================================================================
// UART MODES DEFINITION (SCON Register Configurations)
// ===================================================================
#define UART_MODE_0   0x00    // 8-bit Shift Register (Baud = Fosc / 12)
#define UART_MODE_1   0x50    // 8-bit UART, variable baud rate, REN = 1
#define UART_MODE_2   0x90    // 9-bit UART, fixed baud rate, REN = 1
#define UART_MODE_3   0xD0    // 9-bit UART, variable baud rate, REN = 1
   
// ===================================================================
// SMOD BAUD RATE MULTIPLIER CONFIGURATION
// ===================================================================
#define BAUD_NORMAL   0       // SMOD = 0 (Normal Baud Rate)
#define BAUD_DOUBLE   1       // SMOD = 1 (Double Baud Rate)

// ===================================================================
// DATA TYPES AND STRUCTURES
// ===================================================================

/**
 * @brief Software FIFO Ring Buffer (16-bit to preserve RB8 / 9th bit)
 */
typedef struct {
    unsigned int buffer[BUFFER_SIZE]; // Stores full 9-bit word (Bit 8 = RB8)
    volatile unsigned char head;      // Write index (Interrupt Handler)
    volatile unsigned char tail;      // Read index (Main Thread)
    volatile unsigned char overflow;  // Buffer overflow flag
} uart_fifo_t;

/**
 * @brief UART Diagnostics and Status Tracking Structure
 */
typedef struct {
    volatile unsigned long rx_count;      // Total bytes received
    volatile unsigned long tx_count;      // Total bytes transmitted
    volatile unsigned char parity_error;  // Framing/Parity error tracking
    volatile unsigned char frame_error;   // Framing error flag
} uart_stats_t;

// ===================================================================
// EXTERNAL GLOBAL VARIABLES
// ===================================================================
extern uart_fifo_t rx_fifo;
extern uart_stats_t uart_stats;

// ===================================================================
// FUNCTION PROTOTYPES
// ===================================================================

/* Core Drivers */
void UART_Init(unsigned long baudrate, unsigned char double_baud);
void UART_Init_Advanced(unsigned char mode, unsigned long baudrate, unsigned char double_baud);
void UART_TxChar(unsigned char ch);
void UART_TxString(const char *str);
void UART_TxNumber(unsigned int num);
void UART_TxHex(unsigned char val);

/* 9-Bit Transmit/Receive Support (Mode 2 & Mode 3) */
void UART_Tx9Bit(unsigned int data_word);
int  UART_Rx9Bit(unsigned int *data_word);

/* FIFO Operations */
void FIFO_Init(void);
void FIFO_Put(unsigned int data_word);
int  FIFO_Get(unsigned int *data_word);
unsigned char FIFO_IsEmpty(void);
unsigned char FIFO_IsFull(void);

#endif // __UART_H__