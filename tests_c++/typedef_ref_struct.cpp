class SSL_SESSION {
    opaque      sessionID_[ID_LEN];
    opaque      master_secret_[SECRET_LEN];
    Cipher      suite_[SUITE_LEN];
    uint        bornOn_;                        // create time in seconds
    uint        timeout_;                       // timeout in seconds
    RandomPool& random_;                        // will clean master secret
    X509*       peerX509_;
public:
    explicit SSL_SESSION(RandomPool&);
    SSL_SESSION(const SSL&, RandomPool&);
    ~SSL_SESSION();

    const opaque* GetID()      const;
    const opaque* GetSecret()  const;
    const Cipher* GetSuite()   const;
          uint    GetBornOn()  const;
          uint    GetTimeOut() const;
          X509*   GetPeerX509() const;
          void    SetTimeOut(uint);

    SSL_SESSION& operator=(const SSL_SESSION&); // allow assign for resumption
private:
    SSL_SESSION(const SSL_SESSION&);            // hide copy

    void CopyX509(X509*);
};
