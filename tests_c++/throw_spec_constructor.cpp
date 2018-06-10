ICalParameter::ICalParameter() throw(icalerrorenum) : imp(icalparameter_new(ICAL_ANY_PARAMETER)){
}


ICalParameter::ICalParameter(icalparameter_kind kind, string  str) throw(icalerrorenum) 
{ 
	imp = icalparameter_new_from_value_string(kind, str);
 	if (!imp) throw icalerrno;
}
