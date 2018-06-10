class MarshalledArgs {
public:
    MarshalledArgs(JNIMethod* forMethod, va_list args) : mArgs(forMethod->marshallArgs(args)) {}
    ~MarshalledArgs() { if (mArgs != NULL) delete[] mArgs; }

    operator jvalue* () { return mArgs; }
    
private:
    jvalue* mArgs;
};
