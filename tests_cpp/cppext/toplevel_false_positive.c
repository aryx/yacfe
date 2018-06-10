extern unsigned long long sched_clock(void);
extern unsigned long long
task_sched_runtime(struct task_struct *task);



static inline __attribute__((always_inline)) __attribute__((always_inline)) unsigned long __attribute__((warn_unused_result))
__copy_to_user(void *to, const void *from, unsigned long n)
{
       do { __might_sleep("include/asm/uaccess.h", 457); do { } while (0); } while (0);
       return __copy_to_user_inatomic(to, from, n);
}
