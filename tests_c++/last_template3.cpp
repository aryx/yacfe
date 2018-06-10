void main()
{
	//QValueList< QPair<int, QString> >::const_iterator it;
	//QValueList< QPair<int, QString> >::iterator it, itEnd;

	QValueList<GlossaryItem*>::iterator it = m_itemlist.begin();
	
	QValueList<Glossary*>::iterator itGl = m_glossaries.begin();


	list<XmlAttribute>::const_iterator first =  elem.attributes ().begin ();
	
	vector<kvoctrainExpr>::const_iterator first =  vocabulary.begin ();

	
	list<XmlAttribute>::const_iterator first =  elem.attributes ().begin ();
	
	vector<kvoctrainExpr>::const_iterator first =  vocabulary.begin ();
	
	std::vector<Macro*> ms;
}
	
struct HierElem
{
	int id;
	std::vector<int> parents;
	QDomElement el;
};
