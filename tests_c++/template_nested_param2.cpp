void
nsDocument::InitializeFinalizeFrameLoaders()
{
  NS_ASSERTION(mUpdateNestLevel == 0 && !mDelayFrameLoaderInitialization,
               "Wrong time to call InitializeFinalizeFrameLoaders!");
  // Don't use a temporary array for mInitializableFrameLoaders, because
  // loading a frame may cause some other frameloader to be removed from the
  // array. But be careful to keep the loader alive when starting the load!
  while (mInitializableFrameLoaders.Length()) {
    nsRefPtr<nsFrameLoader> loader = mInitializableFrameLoaders[0];
    mInitializableFrameLoaders.RemoveElementAt(0);
    NS_ASSERTION(loader, "null frameloader in the array?");
    loader->ReallyStartLoading();
  }

  PRUint32 length = mFinalizableFrameLoaders.Length();
  if (length > 0) {
    nsTArray<nsRefPtr<nsFrameLoader> > loaders;
    mFinalizableFrameLoaders.SwapElements(loaders);
    for (PRUint32 i = 0; i < length; ++i) {
      loaders[i]->Finalize();
    }
  }
}
