extern "C" NS_EXPORT void JNICALL
MOZILLA_NATIVE(initialize) (JNIEnv* env, jobject)
{
  if (!InitializeJavaGlobals(env)) {
    jclass clazz =
        env->FindClass("org/mozilla/xpcom/XPCOMInitializationException");
    if (clazz) {
      env->ThrowNew(clazz, "Failed to initialize JavaXPCOM");
    }
  }
}
