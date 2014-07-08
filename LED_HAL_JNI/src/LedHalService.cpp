#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <jni.h>
#include <leds_hal.h>
#include <stdio.h>

struct led_control_device_t *led_hal_device = NULL;

static jboolean led_setState(JNIEnv *env, jobject thiz, jbyteArray led)
{
	jbyte led_state[4];
	LOGI("Led HAL JNI: led_setState() is invoked.MC");

	if (led_hal_device == NULL)
	{
		LOGI("Led HAL JNI: led_hal_device was not fetched correctly.");
		return -1;
	}
	else
	{
		env->GetByteArrayRegion(led, 0, 4, led_state);
		return led_hal_device->set_led_state(led_state);
	}
}

static inline int led_control_open(const struct hw_module_t* module,
		struct led_control_device_t** device)
{
	return module->methods->open(module, LED_HARDWARE_MODULE_ID,
			(struct hw_device_t**) device);
}

static jboolean led_init(JNIEnv *env, jclass clazz)
{
	led_module_t *module;

	LOGE("**********MC start find hal MC*********");
	LOGE(LED_HARDWARE_MODULE_ID);

	if (hw_get_module(LED_HARDWARE_MODULE_ID, (const hw_module_t**) &module)
			== 0)
	{
		LOGI("LedService JNI: LED Stub found.MC");
		if (led_control_open(&module->hw_module, &led_hal_device) == 0)
		{
			LOGI("LedService JNI: Got Stub operations.");
			return 0;
		}
	}

	LOGE("LedService JNI: Get Stub operations failed.MC");
	return -1;
}

static const JNINativeMethod methods[] = {
		{ "_init", "()Z", (void *) led_init }, { "_set_state", "([B)Z",
				(void *) led_setState }, };

int register_led_hal_jni(JNIEnv* env)
{
	static const char* const kClassName =
			"mobile/mc/led/hal/service/LedHalService";

	jclass clazz;

	clazz = env->FindClass(kClassName);
	if (clazz == NULL)
	{
		LOGE("Can't find class %s\n", kClassName);
		return -1;
	}
	if (env->RegisterNatives(clazz, methods,
			sizeof(methods) / sizeof(methods[0])) != JNI_OK)
	{
		LOGE("Failed registering methods for %s\n", kClassName);
		return -1;
	}
	return 0;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv* env = NULL;
	jint result = -1;

	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK)
	{
		LOGE("GetEnv failed!");
		return result;
	}

	register_led_hal_jni(env);

	return JNI_VERSION_1_4;
}

