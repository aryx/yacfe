DEFINE_PER_CPU(struct kprobe *, current_kprobe) = NULL;


DEFINE_PER_CPU(spinlock_t, ipi_lock) = SPIN_LOCK_UNLOCKED;

DEFINE_PER_CPU(struct vm_event_state, vm_event_states) = {{0}};
DEFINE_PER_CPU(int, cpu_state) = { 0 };


DEFINE_PER_CPU(char[256], iucv_dbf_txt_buf);
