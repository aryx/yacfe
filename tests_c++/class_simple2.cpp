class nsSpillableStackBuffer
{
protected:

    enum {
        kStackBufferSize = 256
    };

public:

    nsSpillableStackBuffer() :
        mBufferPtr(mBuffer),
        mCurCapacity(kStackBufferSize)
    { }

    ~nsSpillableStackBuffer()
    {
        DeleteBuffer();
    }

    PRBool EnsureCapacity(PRInt32 inCharsCapacity)
    {
        if (inCharsCapacity < mCurCapacity)
            return PR_TRUE;
    
        if (inCharsCapacity > kStackBufferSize)
        {
            DeleteBuffer();
            mBufferPtr = (PRUnichar*)nsMemory::Alloc(inCharsCapacity * sizeof(PRUnichar));
            mCurCapacity = inCharsCapacity;
            return (mBufferPtr != NULL);
        }
    
        mCurCapacity = kStackBufferSize;
        return PR_TRUE;
    }
                
    PRUnichar*  GetBuffer()     { return mBufferPtr;    }
    PRInt32     GetCapacity()   { return mCurCapacity;  }

protected:

    void DeleteBuffer()
    {
        if (mBufferPtr != mBuffer)
        {
            nsMemory::Free(mBufferPtr);
            mBufferPtr = mBuffer;
        }                
    }
  
protected:

    PRUnichar     *mBufferPtr;
    PRUnichar     mBuffer[kStackBufferSize];
    PRInt32       mCurCapacity;

};
