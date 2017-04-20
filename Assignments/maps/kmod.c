#include <linux/mm.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/device.h>
# include <linux/mm.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
MODULE_LICENSE("Dual BSD/GPL");
#define FIRST_MINOR 10
#define NR_DEVS 1		
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myioctl(struct file*fp,unsigned int pid, unsigned long a);
static int myInit(void);
static void myExit(void);
struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myioctl
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
long myioctl(struct file *fp,unsigned int pid,unsigned long a)
{
	struct task_struct *ptr = pid_task(find_vpid(pid),0);
	struct mm_struct *m = ptr ->mm;
	struct file *fptr;
	struct dentry *d_entry; 
	char *buf[100];
	int i = 0;
	// struct path path;
	// struct dentry *dentry;
	// struct super_block *s_block; 
	struct vm_area_struct *vp = m -> mmap;
	printk("******************************************maps implimentation*****************************************************\n");
	while(vp) {
		i = 0;
		printk("%08x\t",vp -> vm_start);
		printk("%08x\t",vp -> vm_end); 
		switch(vp -> vm_flags & 0xf) {
			case VM_NONE:
				printk("---");
				break;
			case VM_READ:
				printk("r--");
				break;
			case VM_WRITE:
				printk("-w-");
				break;
			case VM_EXEC:
				printk("--x");
				break;
			case (VM_READ|VM_WRITE):
				printk("rw-");
				break;
			case (VM_READ|VM_EXEC):
				printk("r-x");
				break;
			case (VM_EXEC | VM_WRITE):
				printk("-wx");
				break;
			case (VM_EXEC|VM_READ|VM_WRITE):
				printk("rwx");
				break;

		}

		if((vp -> vm_flags & 0xf) == (VM_SHARED))
			printk("---");
		else
			printk("p");
		//printk("\n");
		fptr = vp -> vm_file;
		if(fptr) {

			printk("\t%08x",((vp -> vm_pgoff) << 12));
			printk("\t%d:",MAJOR(fptr -> f_path.dentry->d_sb->s_dev));
			printk("%d",MINOR(fptr -> f_path.dentry->d_sb->s_dev));

		}

		else
			printk("\t%08x",0);
		if(fptr){
			d_entry = fptr->f_path.dentry;
			printk("\t%d\t",d_entry->d_inode->i_ino);

			while(*(d_entry-> d_name.name) != '/') {
				// printk("\t%d",fptr -> f_path.dentry->d_inode->i_ino);
				buf[i] = d_entry->d_name.name;
				d_entry = d_entry -> d_parent;
				i++;
			}

			buf[i] = '\0';
			for( ; i >= 0 ; i--) {
				if(*(buf + i) == '\0')
					printk("/home");
				else
					printk("/%s",buf[i]);
			}
		}
		else
			printk("\t\t%d",0);

		printk("\n");
		vp = vp -> vm_next;

	}
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
