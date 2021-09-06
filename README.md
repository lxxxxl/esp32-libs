# esp32-libs
My libraries for ESP32 with ESP-IDF toolchain
## SW-420
SW-420 vibration sensor module library.
Connection example:
| SW-420 | ESP32 |
|--------|-------|
| VCC    | 3.3V  |
| GND    | GND   |
| DO     | 12    |

```C
#include "sw-420.h"

void vibration_detection_callback(bool detected)
{
    printf("vibration: %d\n", detected);
    fflush(stdout);
}
void app_main(void)
{
    // set up DO pin and callback to process vibration detection statuses
    sw_420_init(GPIO_NUM_12, vibration_detection_callback);
    while(1) {
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
```
## UART Baudrate
Allows quickly change UART baudtate.
```C
set_baudrate(UART_NUM_0, UART_BAUDTATE_19200);

char *str = "TESTTEST";
while (true){
    uart_transmit(str, strlen(str));
    vTaskDelay(50);
}
```