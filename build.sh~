#!bin/bash

module=1

echo "Please select which module you want to build："
echo "1:Build all"
echo "2:linux driver"
echo "3:hal"
echo "4:jni"

read module

echo $module

case $module in

1)
source Linux_led/build.sh
source led_hal/build.sh
source LED_HAL_JNI/build.sh;;

2)
source Linux_led/build.sh;;

3)
source led_hal/build.sh;;

4)
source LED_HAL_JNI/build.sh;;

*)
echo "error"

esac
