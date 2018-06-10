#define DECLARE_PER_CPU(type, name) extern __typeof__(type) per_cpu__##name


DECLARE_PER_CPU(char[256], iucv_dbf_txt_buf);
