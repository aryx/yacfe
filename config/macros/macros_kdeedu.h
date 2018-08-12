// time
//  start  21h35: 78%
//         22h08  87.21%

// http://doc.trolltech.com/4.1/signalsandslots.html
// BAD:!!!!!    emit doc->progressChanged(doc, 0);
//BAD:!!!!! public slots:
//bad: 	void update();
#define slots
#define signals public
#define emit


//BAD:!!!!! KDE_EXPORT QDataStream &operator<<( QDataStream & ostream, const ExtDate & date)
#define KDE_EXPORT



//bad: class dmsBox : public KLineEdit  {
//bad: Q_OBJECT
//BAD:!!!!! Q_PROPERTY (bool degType READ degType WRITE setDegType)
#define Q_OBJECT
#define Q_PROPERTY(a)


//BAD:!!!!! class KStarsInterface : virtual public DCOPObject
//bad: {
//bad: 	K_DCOP
#define K_DCOP

//BAD:!!!!! 		virtual ASYNC lookTowards( const QString direction ) = 0;
#define ASYNC void

//#define WFlags int

/*


BAD:!!!!!   if (kv_exp->getType (q_ocol) == QM_NOUN  QM_TYPE_DIV  QM_NOUN_F) {

BAD:!!!!!      type_ok =    expr_type == QM_NOUN  QM_TYPE_DIV  QM_NOUN_S



bad: enum {
BAD:!!!!!   FLI_IOCTL_MISC_CMDS
bad:   FLI_IOCTL_SPECIAL_SET_CMDS
bad:   FLI_IOCTL_SET_CMDS
bad:   FLI_IOCTL_GET_CMDS
bad: };


BAD:!!!!! class eraseTrans : public unary_function<kvoctrainExpr, void>

	int nmajor(0), nminor(0);

BAD:!!!!! 	std::set<unsigned int>		m_levelNums;		///< Numbers of the levels in this session.

BAD:!!!!! 		startProgressBar((int) double((dmax-dmin)/dx)/2);

BAD:!!!!! 	std::multiset<const QListViewItem*, scoreCompare> scores;

BAD:!!!!! 	return Array<const unsigned char>(dictPtr, dictFile.size());

*/
