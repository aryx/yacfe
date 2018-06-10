void nsAccessNodeWrap::InitAccessibility()
{
   ::InitXPAccessibility();

	if (!::GetModuleFileName(NULL, iniPath, sizeof(iniPath)))
		return 1;

}

