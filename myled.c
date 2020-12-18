// SPDX-License-Identifier: GPL-3.0
// /*
//  * Copyright (C) 2020 Ruka Sakurai <All rights reserved.dk>
//  /   
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/delay.h>
MODULE_AUTHOR("Ryuichi Ueda & Sakurai Ruka");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;
static ssize_t led_write(struct file*filp,const char*buf, size_t cunt,loff_t*pos){
	char c;
	if(copy_from_user(&c,buf,sizeof(char)))
		return -EFAULT;

	if(c == '0'){
		gpio_base[10] = 1 << 21;
		gpio_base[10] = 1 << 20;
		gpio_base[7] = 1 << 16;
		gpio_base[10] = 1 << 12;
		gpio_base[10] = 1 << 26;
		gpio_base[10] = 1 << 19;
		gpio_base[10] = 1 << 13;
		gpio_base[7] = 1 << 6;
		gpio_base[7] = 1 << 18;
		gpio_base[10] = 1 << 23;
		gpio_base[10] = 1 << 24;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 27;
		gpio_base[10] = 1 << 22;
		ssleep(1);
		gpio_base[10] = 1 << 21;
		gpio_base[10] = 1 << 20;
		gpio_base[7] = 1 << 16;
		gpio_base[10] = 1 << 12;
		gpio_base[7] = 1 << 26;
		gpio_base[10] = 1 << 19;
		gpio_base[7] = 1 << 13;
		gpio_base[10] = 1 << 6;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 23;
		gpio_base[10] = 1 << 24;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 27;
		gpio_base[10] = 1 << 22;
		ssleep(1);
		gpio_base[7] = 1 << 21;
		gpio_base[10] = 1 << 20;
		gpio_base[7] = 1 << 16;
		gpio_base[10] = 1 << 12;
		gpio_base[10] = 1 << 26;
		gpio_base[10] = 1 << 19;
		gpio_base[10] = 1 << 13;
		gpio_base[10] = 1 << 6;
		gpio_base[10] = 1 << 18;
		gpio_base[10] = 1 << 23;
		gpio_base[7] = 1 << 24;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 27;
		gpio_base[10] = 1 << 22;
		ssleep(1);
		gpio_base[7] = 1 << 21;
		gpio_base[7] = 1 << 20;
		gpio_base[10] = 1 << 16;
		gpio_base[10] = 1 << 12;
		gpio_base[10] = 1 << 26;
		gpio_base[10] = 1 << 19;
		gpio_base[10] = 1 << 13;
		gpio_base[10] = 1 << 6;
		gpio_base[10] = 1 << 18;
		gpio_base[10] = 1 << 23;
		gpio_base[10] = 1 << 24;
		gpio_base[7] = 1 << 17;
		gpio_base[10] = 1 << 27;
		gpio_base[10] = 1 << 22;
		ssleep(1);
		gpio_base[7] = 1 << 21;
		gpio_base[10] = 1 << 20;
		gpio_base[7] = 1 << 16;
		gpio_base[7] = 1 << 12;
		gpio_base[7] = 1 << 26;
		gpio_base[7] = 1 << 19;
		gpio_base[7] = 1 << 13;
		gpio_base[10] = 1 << 6;
		gpio_base[10] = 1 << 18;
		gpio_base[10] = 1 << 23;
		gpio_base[10] = 1 << 24;
		gpio_base[10] = 1 << 17;
		gpio_base[7] = 1 << 27;
		gpio_base[10] = 1 << 22;
		ssleep(1);
		gpio_base[10] = 1 << 21;
		gpio_base[10] = 1 << 20;
		gpio_base[10] = 1 << 16;
		gpio_base[10] = 1 << 12;
		gpio_base[10] = 1 << 26;
		gpio_base[7] = 1 << 19;
		gpio_base[10] = 1 << 13;
		gpio_base[10] = 1 << 6;
		gpio_base[10] = 1 << 18;
		gpio_base[10] = 1 << 23;
		gpio_base[10] = 1 << 24;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 27;
		gpio_base[7] = 1 << 22;
	}else if(c == '1'){
		gpio_base[7] =1 << 21;
		gpio_base[7] =1 << 20;
		gpio_base[7] =1 << 16;
		gpio_base[7] =1 << 12;
		gpio_base[7] =1 << 26;
		gpio_base[7] =1 << 19;
		gpio_base[7] =1 << 13;
		gpio_base[7] =1 << 6;
		gpio_base[10] = 1 << 22;
	}
	printk(KERN_INFO"receive %c\n",c);
	return 1;
}

static struct file_operations led_fops={
	.owner = THIS_MODULE,
	.write = led_write
};
static int __init init_mod(void){
	int retval;
	retval = alloc_chrdev_region(&dev, 0,1,"myled");
	if(retval < 0){
	printk(KERN_ERR " alloc_chrdev_region failed. \n");                                                                        		return retval;
	}
	                                                                                                                                   printk(KERN_INFO "%s is loaded. major:%d\n",__FILE__,MAJOR(dev));
	cdev_init(&cdv, &led_fops);
	retval = cdev_add(&cdv, dev,1);
	if(retval < 0){
		        printk(KERN_ERR " cdev_add failed.major:%d, minor:%d\n",MAJOR(dev),MINOR(dev));
			return retval;
	}
	cls = class_create(THIS_MODULE,"myled");
	if(IS_ERR(cls)){
		printk(KERN_ERR"class_create failed.");
		return PTR_ERR(cls);
	
	}
	device_create(cls, NULL, dev,NULL,"myled%d",MINOR(dev));
	gpio_base = ioremap_nocache(0xfe200000, 0xA0);

	const u32 led_A = 26;
	const u32 index_A = led_A/10;
	const u32 shift_A = (led_A%10)*3;
	const u32 mask_A = ~(0x7 << shift_A);
	gpio_base[index_A] = (gpio_base[index_A] & mask_A) | (0x1 << shift_A);

	const u32 led_B = 6;
	const u32 index_B = led_B/10;
	const u32 shift_B = (led_B%10)*3;
	const u32 mask_B = ~(0x7 << shift_B);
	gpio_base[index_B] = (gpio_base[index_B] & mask_B) | (0x1 << shift_B);

	const u32 led_C = 20;
	const u32 index_C = led_C/10;
	const u32 shift_C = (led_C%10)*3;
	const u32 mask_C = ~(0x7 << shift_C);
	gpio_base[index_C] = (gpio_base[index_C] & mask_C) | (0x1 << shift_C);

	const u32 led_D = 13;
	const u32 index_D = led_D/10;
	const u32 shift_D = (led_D%10)*3;
	const u32 mask_D = ~(0x7 << shift_D);
	gpio_base[index_D] = (gpio_base[index_D] & mask_D) | (0x1 << shift_D);

	const u32 led_E = 16;
	const u32 index_E = led_E/10;
	const u32 shift_E = (led_E%10)*3;
	const u32 mask_E = ~(0x7 << shift_E);
	gpio_base[index_E] = (gpio_base[index_E] & mask_E) | (0x1 << shift_E);

	const u32 led_F = 19;
	const u32 index_F = led_F/10;
	const u32 shift_F = (led_F%10)*3;
	const u32 mask_F = ~(0x7 << shift_F);
	gpio_base[index_F] = (gpio_base[index_F] & mask_F) | (0x1 << shift_F);

	const u32 led_G = 20;
	const u32 index_G = led_G/10;
	const u32 shift_G = (led_G%10)*3;
	const u32 mask_G = ~(0x7 << shift_G);
	gpio_base[index_G] = (gpio_base[index_G] & mask_G) | (0x1 << shift_G);

	const u32 led_DP = 12;
	const u32 index_DP = led_DP/10;
	const u32 shift_DP = (led_DP%10)*3;
	const u32 mask_DP = ~(0x7 << shift_DP);
	gpio_base[index_DP] = (gpio_base[index_DP] & mask_DP) | (0x1 << shift_DP);

	const u32 led_5 =18;
	const u32 index_5 = led_5/10;
	const u32 shift_5 = (led_5%10)*3;
	const u32 mask_5 = ~(0x7 << shift_5);
	gpio_base[index_5] = (gpio_base[index_5] & mask_5) | (0x1 << shift_5);

	const u32 led_4 =23;
	const u32 index_4 = led_4/10;
	const u32 shift_4 = (led_4%10)*3;
	const u32 mask_4 = ~(0x7 << shift_4);
	gpio_base[index_4] = (gpio_base[index_4] & mask_4) | (0x1 << shift_4);

	const u32 led_3 =24;
	const u32 index_3 = led_3/10;
	const u32 shift_3 = (led_3%10)*3;
	const u32 mask_3 = ~(0x7 << shift_3);
	gpio_base[index_3] = (gpio_base[index_3] & mask_3) | (0x1 << shift_3);

	const u32 led_2 =17;
	const u32 index_2 = led_2/10;
	const u32 shift_2 = (led_2%10)*3;
	const u32 mask_2 = ~(0x7 << shift_2);
	gpio_base[index_2] = (gpio_base[index_2] & mask_2) | (0x1 << shift_2);

	const u32 led_1 =27;
	const u32 index_1 = led_1/10;
	const u32 shift_1 = (led_1%10)*3;
	const u32 mask_1 = ~(0x7 << shift_1);
	gpio_base[index_1] = (gpio_base[index_1] & mask_1) | (0x1 << shift_1);

	const u32 led_0 =22;
	const u32 index_0 = led_0/10;
	const u32 shift_0 = (led_0%10)*3;
	const u32 mask_0 = ~(0x7 << shift_0);
	gpio_base[index_0] = (gpio_base[index_0] & mask_0) | (0x1 << shift_0);
	return 0;
}
static void __exit cleanup_mod(void){
	cdev_del(&cdv);
	device_destroy(cls, dev);
	class_destroy(cls);
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "%s is unloaded. major:%d\n",__FILE__,MAJOR(dev));
}
module_init(init_mod);
module_exit(cleanup_mod);
