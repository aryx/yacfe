using namespace Mozilla::Embedding;

// Silly class for holding on to a static UTF8Encoding so that we
// don't need to create a new one in every call to CopyString()...
/*__gc*/ class UTF8EncodingHolder
{
public:
  static Text::UTF8Encoding *sUTF8Encoding = new Text::UTF8Encoding();
};
