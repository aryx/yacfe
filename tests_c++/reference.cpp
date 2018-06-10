int chaine2::chaine(chaine &notre_chaine)
{
  int longueur = notre_chaine.lg;

  testnull(pt);
  
  testnull(strcpy(pt,notre_chaine.pt));

  lg = longueur;

}
