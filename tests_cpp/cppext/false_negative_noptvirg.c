int SiS300Sync(struct sis_video_info *ivideo)
{
	SiS300Idle
}



void api_remove_complete(void)
{
	DBG_PRV1(("api_remove_complete"))
}


void api_remove_complete(void)
{

    if ( !(data & RISC_INT) )
    {
        /* spurious interrupts can happen legally */
        DEBUG(printk("scsi(%d): Spurious interrupt - ignoring\n",(int)ha->host_no));
        COMTRACE('X')
    }
}



static inline void
scbq_insert_head(volatile scb_queue_type *queue, struct aic7xxx_scb *scb)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,1,95)
  unsigned long cpu_flags;
#endif

  DRIVER_LOCK
  scb->q_next = queue->head;
  queue->head = scb;
  if (queue->tail == NULL)       /* If list was empty, update tail. */
    queue->tail = queue->head;
  DRIVER_UNLOCK
}


//void *TransmitBufferSet(APPL * appl, dword ref)
//{
//	appl->xbuffer_used[ref] = true;
//	DBG_PRV1(("%d:xbuf_used(%d)", appl->Id, ref + 1))
//	    return (void *) ref;
//}

