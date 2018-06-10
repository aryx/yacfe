enum phases
  {
  idle,
  data_out,
  data_in,
  command_ph,
  status_ph,
  message_out,
  message_in
  };

static PVOID dc390_phase0[]={
       dc390_DataOut_0,
       dc390_DataIn_0,
       dc390_Command_0,
       dc390_Status_0,
       dc390_Nop_0,
       dc390_Nop_0,
       dc390_MsgOut_0,
       dc390_MsgIn_0,
       dc390_Nop_1
       };

