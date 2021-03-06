#ifndef DEF_UART_BAUDRATE
#define DEF_UART_BAUDRATE

#include "driver/uart.h"

typedef enum {
    UART_BAUDTATE_75 = 75,
    UART_BAUDTATE_150 = 150,
    UART_BAUDTATE_300 = 300,
    UART_BAUDTATE_600 = 600,
    UART_BAUDTATE_1200 = 1200,
    UART_BAUDTATE_1800 = 1800,
    UART_BAUDTATE_2400 = 2400,
    UART_BAUDTATE_3600 = 3600,
    UART_BAUDTATE_4800 = 4800,
    UART_BAUDTATE_7200 = 7200,
    UART_BAUDTATE_9600 = 9600,
    UART_BAUDTATE_14400 = 14400,
    UART_BAUDTATE_19200 = 19200,
    UART_BAUDTATE_28800 = 28800,
    UART_BAUDTATE_38400 = 38400,
    UART_BAUDTATE_57600 = 57600,
    UART_BAUDTATE_115200 = 115200,
    UART_BAUDTATE_230400 = 230400,
    UART_BAUDTATE_460800 = 460800,
    UART_BAUDTATE_614400 = 614400,
    UART_BAUDTATE_921600 = 921600,
    UART_BAUDTATE_1228800 = 1228800
} uart_baudrate_t;

#define UART_RX_BUFFER_SIZE 2048
#define UART_TX_BUFFER_SIZE 2048

/**
 * @brief set UART baudrate.
 *
 * @param uart_num UART numder. Can be UART_NUM_0, UART_NUM_1, etc
 * @param baudrate needed baudrate
 * @return esp_err_t
 */
esp_err_t set_baudrate(uint8_t uart_num, uart_baudrate_t baudrate);

#endif /* DEF_UART_BAUDRATE */
