#include "uart_baudrate.h"

esp_err_t set_baudrate(uint8_t uart_num, uart_baudrate_t baudrate)
{
    esp_err_t ret;

    uart_config_t uart_config = {
        .baud_rate = baudrate,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };

    // init UART buffers
    ret = uart_driver_install(uart_num, UART_RX_BUFFER_SIZE, UART_TX_BUFFER_SIZE, 0, NULL, 0);
    if (!ret)
        return ret;

    // Configure UART parameters
    ret = uart_param_config(uart_num, &uart_config);

    return ret;
}

