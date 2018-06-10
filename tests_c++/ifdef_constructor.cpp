class nsTString_CharT {

      explicit
#ifdef MOZ_V1_STRING_ABI
      nsTString_CharT( const abstract_string_type& readable )
#else
      nsTString_CharT( const substring_type& readable )
#endif
        : substring_type()
        {
          Assign(readable);
        }


}
