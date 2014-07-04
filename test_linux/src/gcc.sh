arm-linux-gcc -static -o test-hal test.c
adb push test-hal /data/local
