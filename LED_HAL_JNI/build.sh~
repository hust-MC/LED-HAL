#!bin/bash

cd /root/android/source_code/android-4.0.3_r1
source build/envsetup.sh

cd frameworks/base/services/led_hal_jni
mm

#cp  /root/android/source_code/android-4.0.3_r1/out/target/product/generic/system/lib/led_hal_jni.so ./

adb push led_hal_jni.so /system/lib
