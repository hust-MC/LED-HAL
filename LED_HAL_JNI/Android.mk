# Android.mk
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE:= led_hal_jni

#LOCAL_MODULE_PATH := /root/android/adt-bundle-linux-x86-20140321/eclipse/workspace/MC_LED_HAL/leds_hal_jni

LOCAL_SRC_FILES:= src/LedHalService.cpp
   

LOCAL_SHARED_LIBRARIES := \
	libandroid_runtime \
	libcutils \
	libhardware \
	libhardware_legacy \
	libnativehelper \
        libsystem_server \
	libutils \
	libui \
        libsurfaceflinger_client
       
  
LOCAL_C_INCLUDES += \
	$(JNI_H_INCLUDE) \
        frameworks/base/services/led_hal_jni/inc

LOCAL_PRELINK_MODULE := false

include $(BUILD_SHARED_LIBRARY)


    
