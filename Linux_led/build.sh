#!leds.sh

make -C /root/android/source_code/linux-3.0.8/ M=/root/android/adt-bundle-linux-x86-20140321/eclipse/workspace/MC_LED_HAL/Linux_led/src
adb push /root/android/adt-bundle-linux-x86-20140321/eclipse/workspace/MC_LED_HAL/Linux_led/src/linux_led.ko /data/local
adb shell rmmod linux_led
adb shell insmod /data/local/linux_led.ko
