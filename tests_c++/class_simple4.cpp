class NewObjectArrayMessage : public JavaMessage {
    jsize len;
	jclass clazz;
	jobject init;
	jobjectArray* result;
public:
	NewObjectArrayMessage(jsize len, jclass clazz, jobject init, jobjectArray* result)
	{
	    this->len = len;
		this->clazz = clazz;
		this->init = init;
		this->result = result;
	}

	virtual void execute(JNIEnv* env)
	{
		*result = env->NewObjectArray(len, clazz, init);
#if LOCAL_REFS_ARE_GLOBAL
        *result = (jobjectArray) ToGlobalRef(env, *result);
#endif
	}
};
