
//typedef int overrides; 

static int valid_prefix(u_char *Byte, u_char __user **fpu_eip,
			overrides *override)
{
  u_char byte;
  u_char __user *ip = *fpu_eip;

   *override = (overrides) { 0, 0, PREFIX_DEFAULT };       /* defaults */
}
