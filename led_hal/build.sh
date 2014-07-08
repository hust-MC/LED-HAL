#!build.sh

cd /root/android/source_code/android-4.0.3_r1/
source build/envsetup.sh
cd hardware/led_hal
mm
cp /root/android/source_code/android-4.0.3_r1/out/target/product/generic/system/lib/hw/led_hal.default.so ./

adb push led_hal.default.so /system/lib/hw

cd /root/android/adt-bundle-linux-x86-20140321/eclipse/workspace/MC_LED_HAL
