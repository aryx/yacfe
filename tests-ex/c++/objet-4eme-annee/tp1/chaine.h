#ifndef _CHAINE_H_
#define _CHAINE_H_

#include <stdio.h>

class chaine {
	
  
protected:
  char *pt;
  int lg;

public:
  chaine() { pt = NULL; lg=0; }
  chaine(const char *);
  chaine(const chaine &);
  ~chaine();

  void afficher() const;

  chaine & operator=(const chaine &);
  chaine & operator+=(const chaine &);
  chaine & operator-=(const chaine &);
  char & operator[](int);

protected:
  friend int chaine_strcmp(const chaine &c1,const chaine &c2);

public:

  friend bool operator<(const chaine &, const chaine &);
  friend bool operator>(const chaine &,const chaine &);
  friend bool operator==(const chaine &,const chaine &); 
  friend chaine operator+(const chaine &c1,const chaine &c2);
  friend chaine operator-(const chaine &c1,const chaine &c2);

};


#endif
