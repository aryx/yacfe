static int onyx_prepare(struct codec_info_item *cii,
			struct bus_info *bi,
			struct snd_pcm_substream *substream)
{
	u8 v;
	struct onyx *onyx = cii->codec_data;
	int err = -EBUSY;

	mutex_lock(&onyx->mutex);

#ifdef SNDRV_PCM_FMTBIT_COMPRESSED_16BE
	if (substream->runtime->format == SNDRV_PCM_FMTBIT_COMPRESSED_16BE) {
		/* mute and lock analog output */
		onyx_read_register(onyx, ONYX_REG_DAC_CONTROL, &v);
		if (onyx_write_register(onyx /* pad, manque une virgule la? */
					ONYX_REG_DAC_CONTROL,
					v | ONYX_MUTE_RIGHT | ONYX_MUTE_LEFT))
			goto out_unlock;
 		onyx->analog_locked = 1;
		err = 0;
		goto out_unlock;
	}
#endif

}
