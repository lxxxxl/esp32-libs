/*----------------------------------------------------------------------------/
/ SW-420 - SW-420 vibration sensor module library
/----------------------------------------------------------------------------*/
#include "sw-420.h"


#define ESP_INTR_FLAG_DEFAULT 0

static xQueueHandle gpio_evt_queue = NULL;
vibration_detection_callback vdc_ptr = NULL;
bool previous_vibration_detected = 0;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}

static void sw420_task(void* arg)
{
    uint32_t io_num;
	bool vibration_detected;
    while (1) {
        if(!xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY))
			continue;
		vibration_detected = gpio_get_level(io_num);
		// process only vibration detection state tranitions
		if (vibration_detected == previous_vibration_detected)
			continue;
		
		previous_vibration_detected = vibration_detected;
		// send vibration detection status to user app via callback provided
		if (vdc_ptr != NULL)
			vdc_ptr(vibration_detected);
    }
}

void sw_420_init(uint32_t data_pin, vibration_detection_callback vdc)
{
	gpio_config_t io_conf;

    //interrupt of any edge
    io_conf.intr_type = GPIO_INTR_ANYEDGE;
    //bit mask of the pins
    io_conf.pin_bit_mask = 1ULL << data_pin;
    //set as input mode
    io_conf.mode = GPIO_MODE_INPUT;

    gpio_config(&io_conf);

	// save pointer to user callback
	vdc_ptr = vdc;

    //create a queue to handle gpio event from isr
    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    //start gpio task
    xTaskCreate(sw420_task, "sw420_task", 2048, NULL, 10, NULL);

    //install gpio isr service
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    //hook isr handler for specific gpio pin
    gpio_isr_handler_add(data_pin, gpio_isr_handler, (void*) data_pin);
}
