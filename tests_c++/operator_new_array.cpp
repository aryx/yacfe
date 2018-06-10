void* operator new[]( size_t size )
{
    return GC_MALLOC( size );
}


void operator delete[]( void* obj )
{
    GC_FREE( obj );
}
