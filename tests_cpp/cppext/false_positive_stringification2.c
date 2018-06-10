static void snd_pcm_oss_proc_read(struct snd_info_entry *entry,
				  struct snd_info_buffer *buffer)
{
	struct snd_pcm_str *pstr = entry->private_data;
	struct snd_pcm_oss_setup *setup = pstr->oss.setup_list;
	mutex_lock(&pstr->oss.setup_mutex);
	while (setup) {
		snd_iprintf(buffer, "%s %u %u%s%s%s%s%s%s\n",
			    setup->task_name,
			    setup->periods,
			    setup->period_size,
 			    setup->disable ? " disable" : "",
			    setup->direct ? " direct" : "",
			    setup->block ? " block" : "",
			    setup->nonblock ? " non-block" : "",
			    setup->partialfrag ? " partial-frag" : "",
			    setup->nosilence ? " no-silence" : "");
		setup = setup->next;
	}
	mutex_unlock(&pstr->oss.setup_mutex);
}
