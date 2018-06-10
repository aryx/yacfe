BAD:!!!!!     NS_STID_FOR_INDEX(i) {
bad:       if (mLanguageArray[i] != nsnull) {
bad:         mLanguageArray[i]->ShutDown();
bad:         mLanguageArray[i] = nsnull;
bad:       }
bad:     }
