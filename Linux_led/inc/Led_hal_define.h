/*
 * Led_hal_define.h
 *
 *  Created on: 2014年6月24日
 *      Author: root
 */

#ifndef LED_HAL_DEFINE_H
#define LED_HAL_DEFINE_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/delay.h>

#include <mach/gpio.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>

#include <asm/uaccess.h>

#define DEVICE_NAME "MC_LED_HAL"
static unsigned char mem[10];
static int ret;

static int led_gpios[] = { S5PV210_GPJ2(0), S5PV210_GPJ2(1), S5PV210_GPJ2(2),
		S5PV210_GPJ2(3), };

#endif
