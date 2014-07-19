#include "../inc/Led_hal_define.h"


static ssize_t mc_led_hal_write(struct file *file, const char __user *buf,
		size_t count, loff_t *ppos)
{
	int i;
	print_debug("count = %d\n", count);
	for (i = 0; i < count; i++)
	{
		print_debug("%d\n", buf[i]);
	}
	if (copy_from_user(mem, buf, count))
	{
		print_debug("error:copy error");
		return -EFAULT;
	}
	else if (count > 4)
	{
		print_debug("error:count = %d > 4 \n", count);
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			gpio_set_value(led_gpios[i], mem[i]);
		}
		print_debug("write success\n");
	}
	return count;
}

//owner表示设备事件回调函数应用于拿些驱动模块; THIS_MODULE表示应用于当前驱动模块
static struct file_operations dev_fops = { .owner = THIS_MODULE, .write =
		mc_led_hal_write };

static struct miscdevice misc = { .minor = MISC_DYNAMIC_MINOR, .name =
DEVICE_NAME, .fops = &dev_fops };

static int mc_led_hal_init(void)
{
	ret = misc_register(&misc);              //成功注册，返回非0整数，失败返回0
	print_debug("mc_led_hal_init_success:%d\n", ret);
	return ret;
}

static void mc_led_hal_exit(void)
{
	misc_deregister(&misc);
	print_debug("mc_led_hal_exit_success\n");
}

module_init(mc_led_hal_init);
module_exit(mc_led_hal_exit);

MODULE_AUTHOR("MC");
MODULE_DESCRIPTION("Use hal to drive leds.");
MODULE_ALIAS("MC_HAL.");
MODULE_LICENSE("GPL");

