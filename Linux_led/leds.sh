#!leds.sh

make -C ~/android/source_code/linux-3.0.8/ M=/root/android/adt-bundle-linux-x86-20140321/eclipse/workspace/MC_LED_HAL/Linux_led/src
adb push /root/android/adt-bundle-linux-x86-20140321/eclipse/workspace/MC_LED_HAL/Linux_led/src/Led_hal.ko /data/local
adb shell rmmod Led_hal
adb shell insmod /data/local/Led_hal.ko
