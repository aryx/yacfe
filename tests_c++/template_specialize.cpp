// template <> 
NS_SPECIALIZE_TEMPLATE
struct string_class_traits<char>
  {
    typedef char* pointer;
    typedef nsCString implementation_t;
    
    static basic_nsLiteralString<char> literal_hello() { return ::literal_hello(pointer()); }
  };
