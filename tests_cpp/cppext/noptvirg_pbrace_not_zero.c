/* the { is not in column zero so dont have InFunction information */

static void do_interrupt_handler(int irq, void *shap, struct pt_regs *regs) {
   unsigned int j;
   SPIN_FLAGS

   /* Check if the interrupt must be processed by this handler */
   if ((j = (unsigned int)((char *)shap - sha)) >= num_boards) return;

   SPIN_LOCK_SAVE
   ihdlr(irq, j);
   SPIN_UNLOCK_RESTORE
}


