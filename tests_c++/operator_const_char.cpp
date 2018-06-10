class tmpString
{
public:
	tmpString(const char *str1,
		  const char *str2 = 0,
		  const char *str3 = 0,
		  const char *str4 = 0,
		  const char *str5 = 0);
	~tmpString()                      { delete [] s_; }
 	operator const char *()           { return (s_); }

private:
	char *s_;
};
