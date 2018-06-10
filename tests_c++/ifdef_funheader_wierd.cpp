void 
#ifdef XP_OS2_VACPP
_Optlink
#endif
threadmain(void *mytag)
{
    threadarg arg;

    arg.mytag = mytag;

    threadwork(&arg);
}
