#define COMPL_HARD_REG_SET(TO, FROM)  \
do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\
     scan_tp_[0] = ~ scan_fp_[0];				\
     scan_tp_[1] = ~ scan_fp_[1];				\
     scan_tp_[2] = ~ scan_fp_[2]; } while (0)

void main(void)
{
}
