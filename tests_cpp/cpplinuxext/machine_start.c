MACHINE_START(OMAP_FSAMPLE, "OMAP730 F-Sample")
/* Maintainer: Brian Swetland <swetland@google.com> */
 	.phys_io	= 0xfff00000,
	.io_pg_offst	= ((0xfef00000) >> 18) & 0xfffc,
	.boot_params	= 0x10000100,
	.map_io		= omap_fsample_map_io,
	.init_irq	= omap_fsample_init_irq,
	.init_machine	= omap_fsample_init,
	.timer		= &omap_timer,
MACHINE_END


MACHINE_START(VOICEBLUE, "VoiceBlue OMAP5910")
	/* Maintainer: Ladislav Michl <michl@2n.cz> */
 	.phys_io	= 0xfff00000,
	.io_pg_offst	= ((0xfef00000) >> 18) & 0xfffc,
	.boot_params	= 0x10000100,
	.map_io		= voiceblue_map_io,
	.init_irq	= voiceblue_init_irq,
	.init_machine	= voiceblue_init,
	.timer		= &omap_timer,
MACHINE_END

define_machine(mpc834x_itx) {
	.name			= "MPC834x ITX",
	.probe			= mpc834x_itx_probe,
	.setup_arch		= mpc834x_itx_setup_arch,
	.init_IRQ		= mpc834x_itx_init_IRQ,
	.get_irq		= ipic_get_irq,
	.restart		= mpc83xx_restart,
	.time_init		= mpc83xx_time_init,
	.calibrate_decr		= generic_calibrate_decr,
	.progress		= udbg_progress,
};
