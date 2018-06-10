unsigned char __res[sizeof(RESIDUAL)] = {0,};
RESIDUAL *res = (RESIDUAL *)&__res;

unsigned char * PnP_SUB_TYPES[] __initdata = {
  "\001\000SCSIController",
  "\001\001IDEController",
  "\001\002FloppyController",
  "\001\003IPIController",
  "\001\200OtherMassStorageController",
  "\002\000EthernetController",
  "\002\001TokenRingController",
  "\002\002FDDIController",
  "\002\0x80OtherNetworkController",
  "\003\000VGAController",
  "\003\001SVGAController",
  "\003\002XGAController",
  "\003\200OtherDisplayController",
  "\004\000VideoController",
  "\004\001AudioController",
  "\004\200OtherMultimediaController",
  "\005\000RAM",
  "\005\001FLASH",
  "\005\200OtherMemoryDevice",
  "\006\000HostProcessorBridge",
  "\006\001ISABridge",
  "\006\002EISABridge",
  "\006\003MicroChannelBridge",
  "\006\004PCIBridge",
  "\006\005PCMCIABridge",
  "\006\006VMEBridge",
  "\006\200OtherBridgeDevice",
  "\007\000RS232Device",
  "\007\001ATCompatibleParallelPort",
  "\007\200OtherCommunicationsDevice",
  "\010\000ProgrammableInterruptController",
  "\010\001DMAController",
  "\010\002SystemTimer",
  "\010\003RealTimeClock",
  "\010\004L2Cache",
  "\010\005NVRAM",
  "\010\006PowerManagement",
  "\010\007CMOS",
  "\010\010OperatorPanel",
  "\010\011ServiceProcessorClass1",
  "\010\012ServiceProcessorClass2",
  "\010\013ServiceProcessorClass3",
  "\010\014GraphicAssist",
  "\010\017SystemPlanar",
  "\010\200OtherSystemPeripheral",
  "\011\000KeyboardController",
  "\011\001Digitizer",
  "\011\002MouseController",
  "\011\003TabletController",
  "\011\0x80OtherInputController",
  "\012\000GeneralMemoryController",
  NULL
};

unsigned char * PnP_INTERFACES[] __initdata = {
  "\000\000\000General",
  "\001\000\000GeneralSCSI",
  "\001\001\000GeneralIDE",
  "\001\001\001ATACompatible",

  "\001\002\000GeneralFloppy",
  "\001\002\001Compatible765",
  "\001\002\002NS398_Floppy",         /* NS Super I/O wired to use index
                                         register at port 398 and data
                                         register at port 399               */
  "\001\002\003NS26E_Floppy",         /* Ports 26E and 26F                  */
  "\001\002\004NS15C_Floppy",         /* Ports 15C and 15D                  */
  "\001\002\005NS2E_Floppy",          /* Ports 2E and 2F                    */
  "\001\002\006CHRP_Floppy",          /* CHRP Floppy in PR*P system         */

  "\001\003\000GeneralIPI",

  "\002\000\000GeneralEther",
  "\002\001\000GeneralToken",
  "\002\002\000GeneralFDDI",

  "\003\000\000GeneralVGA",
  "\003\001\000GeneralSVGA",
  "\003\002\000GeneralXGA",

  "\004\000\000GeneralVideo",
  "\004\001\000GeneralAudio",
  "\004\001\001CS4232Audio",            /* CS 4232 Plug 'n Play Configured    */

  "\005\000\000GeneralRAM",
  /* This one is obviously wrong ! */
  "\005\000\000PCIMemoryController",    /* PCI Config Method                  */
  "\005\000\001RS6KMemoryController",   /* RS6K Config Method                 */
  "\005\001\000GeneralFLASH",

  "\006\000\000GeneralHostBridge",
  "\006\001\000GeneralISABridge",
  "\006\002\000GeneralEISABridge",
  "\006\003\000GeneralMCABridge",
  /* GeneralPCIBridge = 0, */
  "\006\004\000PCIBridgeDirect",
  "\006\004\001PCIBridgeIndirect",
  "\006\004\002PCIBridgeRS6K",
  "\006\005\000GeneralPCMCIABridge",
  "\006\006\000GeneralVMEBridge",

  "\007\000\000GeneralRS232",
  "\007\000\001COMx",
  "\007\000\002Compatible16450",
  "\007\000\003Compatible16550",
  "\007\000\004NS398SerPort",         /* NS Super I/O wired to use index
                                         register at port 398 and data
                                         register at port 399               */
  "\007\000\005NS26ESerPort",         /* Ports 26E and 26F                  */
  "\007\000\006NS15CSerPort",         /* Ports 15C and 15D                  */
  "\007\000\007NS2ESerPort",          /* Ports 2E and 2F                    */

  "\007\001\000GeneralParPort",
  "\007\001\001LPTx",
  "\007\001\002NS398ParPort",         /* NS Super I/O wired to use index
                                         register at port 398 and data
                                         register at port 399               */
  "\007\001\003NS26EParPort",         /* Ports 26E and 26F                  */
  "\007\001\004NS15CParPort",         /* Ports 15C and 15D                  */
  "\007\001\005NS2EParPort",          /* Ports 2E and 2F                    */

  "\010\000\000GeneralPIC",
  "\010\000\001ISA_PIC",
  "\010\000\002EISA_PIC",
  "\010\000\003MPIC",
  "\010\000\004RS6K_PIC",

  "\010\001\000GeneralDMA",
  "\010\001\001ISA_DMA",
  "\010\001\002EISA_DMA",

  "\010\002\000GeneralTimer",
  "\010\002\001ISA_Timer",
  "\010\002\002EISA_Timer",
  "\010\003\000GeneralRTC",
  "\010\003\001ISA_RTC",

  "\010\004\001StoreThruOnly",
  "\010\004\002StoreInEnabled",
  "\010\004\003RS6KL2Cache",

  "\010\005\000IndirectNVRAM",        /* Indirectly addressed               */
  "\010\005\001DirectNVRAM",          /* Memory Mapped                      */
  "\010\005\002IndirectNVRAM24",      /* Indirectly addressed - 24 bit      */

  "\010\006\000GeneralPowerManagement",
  "\010\006\001EPOWPowerManagement",
  "\010\006\002PowerControl",         // d1378

  "\010\007\000GeneralCMOS",

  "\010\010\000GeneralOPPanel",
  "\010\010\001HarddiskLight",
  "\010\010\002CDROMLight",
  "\010\010\003PowerLight",
  "\010\010\004KeyLock",
  "\010\010\005ANDisplay",            /* AlphaNumeric Display               */
  "\010\010\006SystemStatusLED",      /* 3 digit 7 segment LED              */
  "\010\010\007CHRP_SystemStatusLED", /* CHRP LEDs in PR*P system           */

  "\010\011\000GeneralServiceProcessor",
  "\010\012\000GeneralServiceProcessor",
  "\010\013\000GeneralServiceProcessor",

  "\010\014\001TransferData",
  "\010\014\002IGMC32",
  "\010\014\003IGMC64",

  "\010\017\000GeneralSystemPlanar",   /* 10/5/95                            */
  NULL
  };
