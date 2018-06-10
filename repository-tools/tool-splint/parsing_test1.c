static inline __attribute__((always_inline)) 
void set_buffer_revoked(struct buffer_head *bh) 
{ 
	set_bit(BH_Revoked, &(bh)->b_state); 
}


void main()
{
}
