STATIC void
qla1280_removeq(scsi_lu_t *q, srb_t *sp)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,1,95)
    unsigned long cpu_flags = 0;
#endif
    DEBUG(sprintf(debug_buff,"Removing from device_q (0x%p)->(0x%p)\n\r",q,sp));
    DEBUG(qla1280_print(debug_buff));
    DRIVER_LOCK
    if (sp->s_prev)
    {
        if ((sp->s_prev->s_next = sp->s_next) != NULL)
            sp->s_next->s_prev = sp->s_prev;
        else
            q->q_last = sp->s_prev;
    }
    else if (!(q->q_first = sp->s_next))
        q->q_last = NULL;
    else
        q->q_first->s_prev = NULL;
    DRIVER_UNLOCK
}


static void issue_cmd (int host_index, unsigned long cmd_reg,
		       unsigned char attn_reg)
{
   unsigned long flags;
   /* must wait for attention reg not busy */
   while (1) {
      IBMLOCK
      if (!(inb(IM_STAT_REG(host_index)) & IM_BUSY)) break;
      IBMUNLOCK
   }
   /* write registers and enable system interrupts */
   outl (cmd_reg, IM_CMD_REG(host_index));
   outb (attn_reg, IM_ATTN_REG(host_index));
   IBMUNLOCK
   return;
}


void main(int i)
{

	if (!(reply->u.hdr.MsgFlags & MPI_MSGFLAGS_CONTINUATION_REPLY)) {
		dmfprintk((KERN_INFO MYNAM ": Original request frame (@%p) header\n", mf));
		DBG_DUMP_REQUEST_FRAME_HDR(mf)
 	}

	  if( !ulStatus )
          {
            PCI_TRACEO( ExchangeID, 0xB8) 
          // submitted to Tach's Outbound Que (ERQ PI incremented)
          // waited for completion for ELS type (Login frames issued
          // synchronously)
 	  }
          else {
	  }

			if (vc->vc_need_wrap || vc->vc_decim)
				FLUSH
 			if (vc->vc_need_wrap) {
				cr(vc);
				lf(vc);
			}



}
