class nsCLineString : public nsFixedCString
{
public:
  nsCLineString() : fixed_string_type(mStorage, sizeof(mStorage), 0) {}
  explicit nsCLineString(const substring_type& str)
    : fixed_string_type(mStorage, sizeof(mStorage), 0)
  {
    Assign(str);
  }

private:
  char_type mStorage[160];
};
