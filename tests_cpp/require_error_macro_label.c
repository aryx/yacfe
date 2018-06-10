//pad: apple code 


OSErr
FSRestoreDefault(
	const FSRef *oldDefault)
{
	OSErr			result;
	FSCatalogInfo	catalogInfo;
	
	/* check parameters */
	require_action(NULL != oldDefault, BadParameter, result = paramErr);
	
	/* Get nodeFlags, vRefNum and dirID (nodeID) of oldDefault */
	result = FSGetCatalogInfo(oldDefault,
		kFSCatInfoNodeFlags + kFSCatInfoVolume + kFSCatInfoNodeID,
		&catalogInfo, NULL, NULL, NULL);
	require_noerr(result, FSGetCatalogInfo);
	
	/* Make sure oldDefault is a directory */
	require_action(0 != (kFSNodeIsDirectoryMask & catalogInfo.nodeFlags), OldDefaultNotDirectory,
		result = dirNFErr);
	
	/* Set the current working directory to oldDefault */
	result = HSetVol(NULL, catalogInfo.volume, catalogInfo.nodeID);
	require_noerr(result, HSetVol);

HSetVol:
OldDefaultNotDirectory:
FSGetCatalogInfo:
BadParameter:

	return ( result );
}
