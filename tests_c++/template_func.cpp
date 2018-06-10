template <class T>
bool
put(PropertiesImpl * impl, const char * name, T value, bool replace){
  if(name == 0){
    impl->setErrno(E_PROPERTIES_INVALID_NAME);
    return false;
  }

  PropertiesImpl * tmp = 0;
  const char * short_name = impl->getPropsPut(name, &tmp);

  if(tmp == 0){
    impl->setErrno(E_PROPERTIES_NO_SUCH_ELEMENT);
    return false;
  }
  
  if(tmp->get(short_name) != 0){
    if(replace){
      tmp->remove(short_name);
    } else {
      impl->setErrno(E_PROPERTIES_ELEMENT_ALREADY_EXISTS);
      return false;
    }
  }
  return tmp->put(new PropertyImpl(short_name, value));  
}
