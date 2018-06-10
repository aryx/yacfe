JM_OJIAPITest(JVMManager_CreateProxyJNI_2) {
	GET_JM_FOR_TEST
	//JNIEnv **jniEnv = nsnull;

	nsresult rc = jvmMgr->CreateProxyJNI(nsnull, nsnull);	
	if (NS_FAILED(rc))
		return TestResult::PASS("Method should fail because no space is allocated for the result pointer.");
	return TestResult::FAIL("CreateProxyJNI", rc);

}

JNI_OJIAPITest(JNIEnv_GetBooleanField_1)
{
  GET_JNI_FOR_TEST

  IMPLEMENT_GetFieldID_METHOD("Test1","name_bool", "Z");
  jboolean value = env->GetBooleanField(NULL, fieldID);
  printf("value = %d\n", (int)value);
  return TestResult::PASS("GetBooleanField with obj = NULL return correct value - do not crash");

}


TM_OJIAPITest(ThreadManager_Notify_2) {
	GET_TM_FOR_TEST
	nsresult rc = threadMgr->Notify(threadMgr);
	if (NS_SUCCEEDED(rc))
		return TestResult::PASS("Method should fail because it can call Notify only being monitor's owner.");
	return TestResult::FAIL("Notify", rc);

}
