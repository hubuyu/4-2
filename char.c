#include <linux/module.h> 
#include <linux/init.h>   
#include <linux/err.h>   
#include <linux/fs.h>   
#include <linux/device.h>   

#define	DEMO_MAJOR	239
#define DEV_NAME	"char_dev"

static struct class *demo_class ;

static ssize_t demo_read(struct file *file, char __user *user_buf, size_t count, loff_t *ppos)
{	
	printk("Now entering %s() \n", __FUNCTION__ );
	return 0 ;
}

static ssize_t demo_write(struct file *file, const char __user *user_buf, size_t count, loff_t *ppos)
{
	printk("Now entering %s() \n", __FUNCTION__ );
	return  0 ;
}

static int demo_open(struct inode *inode, struct file *file)
{
	printk("Now entering %s() \n", __FUNCTION__ );
	return 0 ;
}

static int demo_close(struct inode *inode, struct file *file)
{
	printk("Now entering %s() \n", __FUNCTION__ );
	return 0 ;
}

struct file_operations demo_ops = {
	.owner = THIS_MODULE ,
	.open = demo_open ,
	.release = demo_close ,
	.write = demo_write ,
	.read = demo_read ,
};

static int __init hello_init(void){
	int status ;
	printk("Hello driver world\n");
	status = register_chrdev( DEMO_MAJOR , DEV_NAME , &demo_ops);
	if ( status < 0 ){
		printk("Failed to register char device - %d\n" , DEMO_MAJOR );
		return status ;
	}

	demo_class = class_create(THIS_MODULE , "demo-class");
	if (IS_ERR(demo_class)){
		unregister_chrdev( DEMO_MAJOR , DEV_NAME );
	}

	return 0;
}
	 
static void __exit hello_exit(void){
	printk("Goodbye driver world\n");
    class_destroy(demo_class);
    unregister_chrdev(DEMO_MAJOR , DEV_NAME);

}

module_init(hello_init);
module_exit(hello_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("hubuyu");
MODULE_DESCRIPTION("Lesson 4-2 : Simple char Register ");

