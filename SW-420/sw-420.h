/*----------------------------------------------------------------------------/
/ SW-420 - SW-420 vibration sensor module library
/----------------------------------------------------------------------------*/
#ifndef DEF_SW420
#define DEF_SW420
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "sdkconfig.h"


typedef void (*vibration_detection_callback)(bool);

/**
 * @brief initialize SW-420 communication.
 *
 * @param data_pin pin nubmer to which data pin is connceted.
 * @param vdc      callback to return vibration detection status
 * @return void
 */
void sw_420_init(uint32_t data_pin, vibration_detection_callback vdc);

#endif /* _SW420 */
