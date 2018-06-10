// This packet is sent in response to a CMD_GET_BOXIDS bypass command. For -IIEX
// boards, reports the hardware-specific "asynchronous resource register" on
// each expansion box. Boxes not present report 0xff. For -II boards, the first
// element contains 0x80 for 8-port, 0x40 for 4-port boards.

