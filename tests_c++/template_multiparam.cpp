
void main()
{

	nsAutoBuffer<char, 1024> buffer;

	static nsDataHashtable<nsCStringHashKey, int>* gTldTypes;

   gTldTypes = new nsDataHashtable<nsCStringHashKey, int>();
}
