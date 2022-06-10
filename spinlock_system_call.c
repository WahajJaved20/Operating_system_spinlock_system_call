#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>
#include <linux/syscalls.h>


SYSCALL_DEFINE1(spinLock, int *, x)
{
    static spinlock_t dynamic;
    unsigned long flags;
    spin_lock_init(&dynamic);
    spin_lock_irqsave(&dynamic, flags);
    pr_info("Locked dynamic spinlock\n");
    *x = *x - 1;
    spin_unlock_irqrestore(&dynamic, flags);
    pr_info("Unlocked dynamic spinlock\n");
    printk("New value: %d\n", *x);
    return 0;
}
