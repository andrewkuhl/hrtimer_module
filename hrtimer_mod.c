#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("andrewkuhl");
MODULE_DESCRIPTION("test hrtimer");

static struct hrtimer test_hrtimer;
static u64 sampling_period_ms = 1000; 
static u32 loop = 0;

static enum hrtimer_restart test_hrtimer_handler(struct hrtimer *timer)
{
    pr_info("test_hrtimer_handler: %u\n", ++loop);
    hrtimer_forward_now(&test_hrtimer, ms_to_ktime(sampling_period_ms));
    return HRTIMER_RESTART;
}

static int __init hrtimer_mod_init(void)
{
    hrtimer_init(&test_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
    test_hrtimer.function = &test_hrtimer_handler;
    hrtimer_start(&test_hrtimer, ms_to_ktime(sampling_period_ms), HRTIMER_MODE_REL);
    pr_info("init test_hrtimer.\n");

    return 0;
}

static void __exit hrtimer_mod_exit(void)
{
    hrtimer_cancel(&test_hrtimer );
    pr_info("exit test_hrtimer.\n");
    return;
}

module_init(hrtimer_mod);
module_exit(hrtimer_mod);
