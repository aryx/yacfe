
void main(void)
{
		for_each_online_cpu(j)
 			seq_printf(p, "%10lu ", cpu_data[j].ipi_count);
		seq_putc(p, '\n');

}
