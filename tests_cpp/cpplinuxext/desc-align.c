struct de4x5_desc {
    volatile s32 status;
    u32 des1;
    u32 buf;
    u32 next;
    DESC_ALIGN
};
