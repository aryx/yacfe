struct SprintfStateStr {
    int (*stuff)(SprintfState *ss, const PRUnichar *sp, PRUint32 len);

    PRUnichar *base;
    PRUnichar *cur;
    PRUint32 maxlen;

    void *stuffclosure;
};
