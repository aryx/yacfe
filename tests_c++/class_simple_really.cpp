class si_SignonCompositeURLStruct : public si_SignonURLStruct {
public:
  si_SignonURLStruct *primaryUrl;
  si_SignonURLStruct *legacyUrl;
};
