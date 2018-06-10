static void sn_set_affinity_irq(unsigned int irq, cpumask_t mask)
{
	struct sn_irq_info *sn_irq_info, *sn_irq_info_safe;
	nasid_t nasid;
	int slice;

	nasid = cpuid_to_nasid(first_cpu(mask));
	slice = cpuid_to_slice(first_cpu(mask));

	list_for_each_entry_safe(sn_irq_info, sn_irq_info_safe,
				 sn_irq_lh[irq], list)
		(void)sn_retarget_vector(sn_irq_info, nasid, slice);
}
