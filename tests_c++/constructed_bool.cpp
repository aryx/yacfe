// kdeedu 

void ScriptBuilder::slotINDISetTargetCoordDeviceRA()
{
  ScriptFunction *sf = ScriptList.at( sb->ScriptListBox->currentItem() );

  if ( sf->name() == "setINDITargetCoord" ) {
		//do nothing if box is blank (because we could be clearing boxes while switcing argWidgets)
    if ( argSetTargetCoordINDI->RaBox->text().isEmpty() )
    {
      sf->setValid(false);
      return;
    }
	// pad: 
    bool ok(false);
    dms ra = argSetTargetCoordINDI->RaBox->createDms(false, &ok);
    if ( ok ) {
      
      if (sf->argVal(1) != QString( "%1" ).arg( ra.Hours() ))
      	setUnsavedChanges( true );

      sf->setArg( 1, QString( "%1" ).arg( ra.Hours() ) );
      if ( ( ! sf->argVal(0).isEmpty() ) && ( ! sf->argVal(2).isEmpty() )) sf->setValid( true );
      else sf->setValid(false);

    } else {
      sf->setArg( 1, "" );
      sf->setValid( false );
    }
  } else {
    kdWarning() << i18n( "Mismatch between function and Arg widget (expected %1.)" ).arg( "setINDITargetCoord" ) << endl;
  }
  
}
