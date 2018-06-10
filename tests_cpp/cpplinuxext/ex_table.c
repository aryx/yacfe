static int diag204(unsigned long subcode, unsigned long size, void *addr)
{
	register unsigned long _subcode asm("0") = subcode;
	register unsigned long _size asm("1") = size;

	asm volatile(
		"	diag	%2,%0,0x204\n"
		"0:\n"
 		EX_TABLE(0b,0b)
		: "+d" (_subcode), "+d" (_size) : "d" (addr) : "memory");
	if (_subcode)
		return -1;
	return _size;
}


static int emulate_ldh(struct pt_regs *regs, int toreg)
{
	unsigned long saddr = regs->ior;
	unsigned long val = 0;
	int ret;

	DPRINTF("load " RFMT ":" RFMT " to r%d for 2 bytes\n", 
		regs->isr, regs->ior, toreg);

	__asm__ __volatile__  (
"	mtsp	%4, %%sr1\n"
"1:	ldbs	0(%%sr1,%3), %%r20\n"
"2:	ldbs	1(%%sr1,%3), %0\n"
"	depw	%%r20, 23, 24, %0\n"
"	copy	%%r0, %1\n"
"3:	\n"
"	.section .fixup,\"ax\"\n"
"4:	ldi	-2, %1\n"
	FIXUP_BRANCH(3b)
"	.previous\n"
 	ASM_EXCEPTIONTABLE_ENTRY(1b, 4b)
	ASM_EXCEPTIONTABLE_ENTRY(2b, 4b)
	: "=r" (val), "=r" (ret)
	: "0" (val), "r" (saddr), "r" (regs->isr)
	: "r20", FIXUP_BRANCH_CLOBBER );

	DPRINTF("val = 0x" RFMT "\n", val);

	if (toreg)
		regs->gr[toreg] = val;

	return ret;
}

static inline int __sem_update_count(struct semaphore *sem, int incr)
{
	int old_count, tmp;

	__asm__ __volatile__("\n"
"1:	lwarx	%0,0,%3\n"
"	srawi	%1,%0,31\n"
"	andc	%1,%0,%1\n"
"	add	%1,%1,%4\n"
 	PPC405_ERR77(0,%3)
"	stwcx.	%1,0,%3\n"
"	bne	1b"
	: "=&r" (old_count), "=&r" (tmp), "=m" (sem->count)
	: "r" (&sem->count), "r" (incr), "m" (sem->count)
	: "cc");

	return old_count;
}



asmlinkage int sys_tas(int __user *addr)
{
	int oldval;

	if (!access_ok(VERIFY_WRITE, addr, sizeof (int)))
		return -EFAULT;

	/* atomic operation:
	 *   oldval = *addr; *addr = 1;
	 */
	__asm__ __volatile__ (
 		DCACHE_CLEAR("%0", "r4", "%1")
		"	.fillinsn\n"
		"1:\n"
		"	lock	%0, @%1	    ->	unlock	%2, @%1\n"
		"2:\n"
		/* NOTE:
		 *   The m32r processor can accept interrupts only
		 *   at the 32-bit instruction boundary.
		 *   So, in the above code, the "unlock" instruction
		 *   can be executed continuously after the "lock"
		 *   instruction execution without any interruptions.
		 */
		".section .fixup,\"ax\"\n"
		"	.balign 4\n"
		"3:	ldi	%0, #%3\n"
		"	seth	r14, #high(2b)\n"
		"	or3	r14, r14, #low(2b)\n"
		"	jmp	r14\n"
		".previous\n"
		".section __ex_table,\"a\"\n"
		"	.balign 4\n"
		"	.long 1b,3b\n"
		".previous\n"
		: "=&r" (oldval)
		: "r" (addr), "r" (1), "i"(-EFAULT)
		: "r14", "memory"
#ifdef CONFIG_CHIP_M32700_TS1
		  , "r4"
#endif /* CONFIG_CHIP_M32700_TS1 */
	);

	return oldval;
}
