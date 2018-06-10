static const snd_kcontrol_new_t snd_ac97_controls_master_mono[2] = {
AC97_SINGLE("Master Mono Playback Switch", AC97_MASTER_MONO, 15, 1, 1),
AC97_SINGLE("Master Mono Playback Volume", AC97_MASTER_MONO, 0, 31, 1)
};



static snd_kcontrol_new_t snd_es1938_controls[] = {
ES1938_DOUBLE("Master Playback Volume", 0, 0x60, 0x62, 0, 0, 63, 0),
ES1938_DOUBLE("Master Playback Switch", 0, 0x60, 0x62, 6, 6, 1, 1),
{
	.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
	.name = "Hardware Master Playback Volume",
	.access = SNDRV_CTL_ELEM_ACCESS_READ,
	.info = snd_es1938_info_hw_volume,
	.get = snd_es1938_get_hw_volume,
},
{
	.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
	.name = "Hardware Master Playback Switch",
	.access = SNDRV_CTL_ELEM_ACCESS_READ,
	.info = snd_es1938_info_hw_switch,
	.get = snd_es1938_get_hw_switch,
},
}
