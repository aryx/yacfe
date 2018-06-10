/*******************************************************************************
 *
 * Copyright (C) 1998-1999 by Y. Padioleau, G. Cottenceau, P. Garcia,
 *   G. LeGuelvouit, Y. Zemali, S. Crunchant, X. Michard.
 *
 * Please check out README.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 ******************************************************************************/

#ifndef __MATRICE_H__
#define __MATRICE_H__

#include <vector>
#include <iomanip>

using namespace std;

template <class Type>
class Matrice
{
private:
  
  vector<vector<Type> >   _matrice ;
  int                     _nbColonne ;
  int                     _nbLigne ;

public:

  Matrice (int h = 100 , int l = 100) ;

  Matrice (const Matrice<Type>&) ;

  Matrice<Type>& operator = (const Matrice<Type>&) ;

  int NbColonne () const { return _nbColonne ; }

  int NbLigne   () const { return _nbLigne ; }

  Type  operator () (int i, int j) const { return _matrice[i][j] ; }
  Type& operator () (int i, int j)       { return _matrice[i][j] ; }

  ~Matrice () {}

} ;

template <class Type>
Matrice<Type>::Matrice (int h, int l): _matrice(h), _nbColonne(l),
                                       _nbLigne(h)
{
  for (int i = 0 ; i < h ; i++)
    {
      _matrice[i].resize(l) ;
    }
}

template <class Type>
Matrice<Type>::Matrice (const Matrice<Type>& matrice)
{
  *this = matrice ;
}

template <class Type>
Matrice<Type>& Matrice<Type>::operator = (const Matrice<Type>& matrice)
{
  if (this != &matrice)
    {
      _matrice   = matrice._matrice ;
      _nbColonne = matrice._nbColonne ;
      _nbLigne   = matrice._nbLigne ;
    }
  
  return *this ;
}

template <class Type>
ostream& operator << (ostream& os, const Matrice<Type>& matrice) 
{
  for (int i = 0 ; i < matrice.NbLigne() ; i++)
    {
      for (int j = 0 ; j < matrice.NbColonne() ; j++)
	{
	  os << setw(2) << matrice(i,j) ;
	}
      os << endl ;
    }

  return os ;
}

#endif
