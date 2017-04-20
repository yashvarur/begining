#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 10
#define NR_DEVS 1		

int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);

static int myInit(void);
static void myExit(void);

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = myOpen,
    .release = myRelease
};
char *devname;
int majNo;
static dev_t mydev;
struct cdev *my_cdev;
module_param(devname, charp, 0000);
static struct class *mychar_class;
static struct device *mychar_device;


int myOpen(struct inode *inode, struct file *filep)
{
    printk(KERN_INFO "Open successful\n");
    return 0;
}
int myRelease(struct inode *in, struct file *filep)
{
    printk(KERN_INFO "File released\n");
    return 0;
}
static int __init myInit(void)
{
    int ret = -ENODEV;
    int status;
    printk(KERN_INFO "Initializing character Device\n");
    status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
    if (status < 0) {
        printk(KERN_NOTICE "Device numbers allocation failed: %d\n",status);
        goto err;
    }
    printk(KERN_INFO "Major number allocated = %d   %d\n",MAJOR(mydev), mydev);
    printk(KERN_INFO "Minor number allocated = %d   %d\n",MINOR(mydev), mydev);
    my_cdev = cdev_alloc();
    if (my_cdev==NULL) {
        printk(KERN_ERR "cdev_allocfailed\n");
        goto err_cdev_alloc;
    }
    cdev_init(my_cdev, &fops);
    my_cdev->owner=THIS_MODULE;

    status=cdev_add(my_cdev,mydev,NR_DEVS);
    if (status) {
        printk(KERN_ERR "cdev_addfailed\n");
        goto err_cdev_add;
    }


    mychar_class=class_create(THIS_MODULE, devname);
    if (IS_ERR(mychar_class)) {
        printk(KERN_ERR "class_create()failed\n");
        goto err_class_create;
    }
    mychar_device=device_create(mychar_class,NULL,mydev,NULL,devname);
    if (IS_ERR(mychar_device)){
        printk(KERN_ERR "device_create()failed\n");
        goto err_device_create;
    }
    return 0;
err_device_create:class_destroy(mychar_class);
err_class_create:cdev_del(my_cdev);
err_cdev_add:kfree(my_cdev);
err_cdev_alloc:unregister_chrdev_region(mydev, NR_DEVS);
err:
return ret;

}
static void myExit(void)
{
    printk(KERN_INFO "exiting the character driver\n");
    device_destroy(mychar_class, mydev);
    class_destroy(mychar_class);
    cdev_del(my_cdev);
    unregister_chrdev_region(mydev, NR_DEVS);
    return;
}

module_init(myInit);
module_exit(myExit);
