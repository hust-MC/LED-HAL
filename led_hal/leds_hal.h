#include <hardware/hardware.h>
#include <fcntl.h>
#include <cutils/log.h>

struct led_module_t
{
	struct hw_module_t hw_module;
};
struct led_control_device_t
{
	struct hw_device_t hw_device;
	int (*set_led_state)(char state);
};

#define LED_HARDWARE_MODULE_ID "led_hal"
