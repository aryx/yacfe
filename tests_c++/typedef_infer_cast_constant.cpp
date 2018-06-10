#include "CallingInstanceMethods.h"

//JNI_OJIAPITest(JNIEnv_CallByteMethod_3)
//{
//  GET_JNI_FOR_TEST
void main()
{
  IMPLEMENT_GetMethodID_METHOD("Test1", "Test1_method_byte", "(ZBCSIJFDLjava/lang/String;[Ljava/lang/String;)B");
  jbyte value = env->CallByteMethod(obj, MethodID, (jboolean)JNI_TRUE, (jbyte)MIN_JBYTE, (jchar)'a', (jshort)1, (jint)123, (jlong)0, (jfloat)0., (jdouble)100, (jobject)NULL, (jobject)NULL);
  if(value == MIN_JBYTE){
     return TestResult::PASS("CallByteMethod for public not inherited method (sig = (ZBCSIJFDLjava/lang/String;[Ljava/lang/String;)B) return correct value");
  }else{
     return TestResult::FAIL("CallByteMethod for public not inherited method (sig = (ZBCSIJFDLjava/lang/String;[Ljava/lang/String;)B) return incorrect value");
  }

}
