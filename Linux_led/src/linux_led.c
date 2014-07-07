#include "Led_hal_define.h"

static ssize_t word_count_write(struct file *file, const char __user *buf,
		size_t count, loff_t *ppos)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printk("%d\n", buf[i]);
	}
	if (copy_from_user(mem, buf, count))
	{
		printk("error:copy error");
		return -EFAULT;
	}
	else if (count > 4)
	{
		printk("error:count = %d > 4 \n", count);
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			printk("%d\n", mem[i]);
			gpio_set_value(led_gpios[i], mem[i]);
		}
	}
	return count;
}

//owner表示设备事件回调函数应用于拿些驱动模块; THIS_MODULE表示应用于当前驱动模块
static struct file_operations dev_fops = { .owner = THIS_MODULE, .write =
		word_count_write };

static struct miscdevice misc = { .minor = MISC_DYNAMIC_MINOR, .name =
DEVICE_NAME, .fops = &dev_fops };

static int word_count_init(void)
{
	ret = misc_register(&misc);              //成功注册，返回非0整数，失败返回0
	printk("word_count_init_success:%d\n", ret);
	return ret;
}

static void word_count_exit(void)
{
	misc_deregister(&misc);
	printk("word_count_exit_success\n");
}

module_init(word_count_init);
module_exit(word_count_exit);

MODULE_AUTHOR("MC");
MODULE_DESCRIPTION("Use hal to drive leds.");
MODULE_ALIAS("MC_HAL.");
MODULE_LICENSE("GPL");

