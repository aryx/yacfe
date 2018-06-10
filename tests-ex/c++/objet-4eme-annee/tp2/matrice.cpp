#include <stream.h>
#include "tableau.h"
#include "matrice.h"

class pb_memory_alloc {};

matrice::matrice(unsigned int ligne, unsigned int colonne)
{
  taille_ligne = ligne;
  taille_colonne = colonne;
  
  pt_tab_pt = new (tableau*[ligne]) ;//|| throw pb_memory_alloc() ;

  for (int i = 0; i < taille_ligne; i++)
    pt_tab_pt[i] = new tableau(colonne);// || throw pb_memory_alloc() ;
}

matrice::~matrice()
{
  for (int i = 0; i < taille_ligne; i++)
    delete pt_tab_pt[i];

  delete pt_tab_pt;
}

matrice::matrice(const matrice& mat)
{
  taille_ligne = mat.taille_ligne;
  taille_colonne = mat.taille_colonne;

  pt_tab_pt = new (tableau*[taille_ligne]) ;//|| throw pb_memory_alloc() ;

  for (int i = 0; i < taille_ligne; i++)
    pt_tab_pt[i] = new tableau(taille_colonne);// || throw pb_memory_alloc() ;

  for (int i = 0; i < taille_ligne; i++)
    for (int j = 0; j < taille_colonne; j++)
      (*this)[i][j] = mat[i][j];
    

}


matrice & matrice::operator=(const matrice& mat)
{
  if ((this->taille_ligne != mat.taille_ligne) || 
      (this->taille_colonne != mat.taille_colonne)) {
    cout << "dimension des deux matrice non ientiques";
    exit(0);
  }

  for (int i = 0; i < taille_ligne; i++)
    for (int j = 0; j < taille_colonne; j++)
      (*this)[i][j] = mat[i][j];

  return *this;
}

tableau matrice::operator[](unsigned int ligne) const
{
  if (ligne >= taille_ligne) {
    cout << "erreur lors de l'acces a l'indice de la matrice\n";
    exit(0);
  }
  return *(pt_tab_pt[ligne]);
}



tableau & matrice::operator[](unsigned int ligne)
{
  if (ligne >= taille_ligne) {
    cout << "erreur lors de l'acces a l'indice de la matrice\n";
    exit(0);
  }
  return *(pt_tab_pt[ligne]);
}



ostream & operator<<(ostream &flot ,const matrice &mat)
{
  flot << "la matrice :\n";
  for (int i = 0; i < mat.taille_ligne; i++)
    {
      for (int j = 0; j < mat.taille_colonne; j++)
	flot << mat[i][j];
      
      flot << "\n";
    }
  return flot;
}

matrice operator+(const matrice &mat1,const matrice &mat2)
{
  if ((mat1.taille_ligne != mat2.taille_ligne) || 
      (mat1.taille_colonne != mat2.taille_colonne)) {
    cout << "dimension des deux matrice non ientiques";
    exit(0);
  }
  
  matrice tmp(mat1);
  
  for (int i = 0; i < mat1.taille_ligne; i++)
    for (int j = 0; j < mat1.taille_colonne; j++)
      tmp[i][j] += mat2[i][j];

  return tmp;

}


