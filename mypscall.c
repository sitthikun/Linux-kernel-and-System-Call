#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage int sys_mypscall(void)

{    
      if (printk_ratelimit())
      printk(KERN_INFO "Student ID: D10715805 Student Name:Pichit Sitthikun\n");
      return 0;
}
