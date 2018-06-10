void main()
{
  void* block = ::operator new(inSize);

  ::operator delete(inBlock);
}
