template<typename T>
    struct BoundsContainer
    {
      T* first;
      T* last;
      BoundsContainer(T* _first, T* _last) : first(_first), last(_last)
      { }
    };
