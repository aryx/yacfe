class AddFile : public Action
{
public:
  AddFile() : mFile(NULL) { }

  virtual int Parse(char *line);
  virtual int Prepare(); // check that the source file exists
  virtual int Execute();
  virtual void Finish(int status);

private:
  const char *mFile;
};
