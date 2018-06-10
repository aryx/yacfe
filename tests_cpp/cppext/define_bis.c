#define AVM_FRITZ_PCI		1
#define CFG_RESET_DELAY		5
#define CFG_NUM			6	/* number of configuration items */


#define chip_t vortex_t
#define VORTEX_PCM_TYPE(x) (x->name[40])

#define IRQ_T(info) ((info->flags & ASYNC_SHARE_IRQ) ? SA_SHIRQ : SA_INTERRUPT)

#define IRQ_T(info) ((info->flags & ASYNC_SHARE_IRQ) ? IRQF_SHARED : IRQF_DISABLED)

#define SONIC_IRQ_FLAG SA_INTERRUPT
#define SONIC_IRQ_FLAG IRQF_DISABLED

#define cs4x_mem_map_reserve(page) mem_map_reserve(page)
#define cs4x_mem_map_unreserve(page) mem_map_unreserve(page)

# define PCI_PRESENT pci_present ()
# define PCI_PRESENT (1)

#define pci_present pcibios_present


#define pci_present()				pcibios_present()


#define zr_remap_page_range(a,b,c,d,e) remap_page_range(a,b,c,d,e)

#define DEVICE_NR(device) (minor(device))
#define QUEUE (&sjcd_queue)


#define ARRAY_IS_ACTIVE KERN_INFO \
"multipath: array md%d active with %d out of %d IO paths (%d spare IO paths)\n"

#define RELEVANT_IFLAG(iflag)	(iflag & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK|\
 					  IXON|IXOFF))

#define CS_EXIT_TEST(ret, svc, label) \
if (ret != CS_SUCCESS) { cs_error(link->handle, svc, ret); goto label; }

#define CS_EXIT_TEST(ret, svc, label) \
if (ret != CS_SUCCESS) { cs_error(link, svc, ret); goto label; }


#define CS_CHECK(fn, ret) \
 do { last_fn = (fn); if ((last_ret = (ret)) != 0) goto cs_failed; } while (0)

#define SET_TIMER							\
 	do {								\
 		mod_timer(&device_timer, jiffies + TIMEOUT_VALUE);	\
 	} while (0)

#define PciDeviceFn(d)		((d)&0xff)

#define __PciDev(busn, devfn)	(((busn)<<8)+(devfn))

#define ROCKET_PARANOIA_CHECK
#define ROCKET_SOFT_FLOW
#define ROCKET_DISABLE_SIMUSAGE

#define _INLINE_ inline

#define NUM_UPCI_IDS	(sizeof(upci_ids) / sizeof(upci_ids[0]))


#define pci_set_dma_mask(dev, mask)		dev->dma_mask = mask;

#define pci_find_subsys(id, dev, sid, sdev, pdev) pci_find_device(id,dev,pdev)
#define scsi_set_pci_device(host, pdev)

#define PCI_DEVICE_ID_TEKRAM_TRMS1040           0x0391	/* Device ID    */

#define DC395x_LOCK_IO(dev)   spin_lock_irqsave(((struct Scsi_Host *)dev)->host_lock, flags)


#define SPRINTF(args...) \
       do { if(pos < buffer + length) pos += sprintf(pos, ## args); } while(0)


#define CS_CHECK(fn, args...) \
 while ((last_ret=CardServices(last_fn=(fn),args))!=0) goto cs_failed

#define CFG_CHECK(fn, args...) \
 if (CardServices(fn, args) != 0) goto next_entry




