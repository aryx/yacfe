//JNI_OJIAPITest(JNIEnv_CallStaticCharMethod_1)
//{
//  GET_JNI_FOR_TEST
void main()
{

  IMPLEMENT_GetStaticMethodID_METHOD("Test1", "Test1_method_char_static", "(ZBCSIJFDLjava/lang/String;[Ljava/lang/String;)C");
  char *path = "asdf";
  jstring jpath=env->NewStringUTF("sdsadasdasd");
  jvalue *args  = new jvalue[10];
  args[0].z = JNI_FALSE;
  args[1].b = MIN_JBYTE;

}

void main()
{

  XPTParamDescriptor* newArray = new XPTParamDescriptor[newAvailable];

}
