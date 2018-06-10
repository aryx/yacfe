static /*const*/ struct file_operations cs_midi_fops = {
 	CS_OWNER	CS_THIS_MODULE
	.llseek		= no_llseek,
	.read		= cs_midi_read,
	.write		= cs_midi_write,
	.poll		= cs_midi_poll,
	.open		= cs_midi_open,
	.release	= cs_midi_release,
};

static /*const*/ struct file_operations cs_mixer_fops = {
 	CS_OWNER	CS_THIS_MODULE
	.llseek		= no_llseek,
	.ioctl		= cs_ioctl_mixdev,
	.open		= cs_open_mixdev,
	.release	= cs_release_mixdev,
};
