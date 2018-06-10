#include <stream.h>
#include "tableau.h"
#include "matrice.h"
#include "vect_ligne.h"
#include "vect_colonne.h"

void main()
{
	int i, j;
	const unsigned m=4;
	const unsigned n=3;
	matrice mat1(n,m), mat2(n,m), mat3(n,m);

	i=mat1[0][0];
	vect_ligne vl(n);
	vect_colonne vc(n);

	for (i=0 ; i<n ; i++)
		for (j=0 ; j<m ; j++)
			mat1[i][j] = i*j;

	for (i=0 ; i<n ; i++)
		for (j=0 ; j<m ; j++)
			mat2[i][j] = mat1[i][j]*2 ;
 
	mat3 = mat1 + mat2 ;

	cout << "la matrice mat1 = \n" ;		
	for (i=0 ; i<n ; i++)
	{	
		for (j=0 ; j<m ; j++)
			cout << mat1[i][j]<< " ," ;
		cout << endl;
	}
 
	cout << "la matrice mat2 = \n" ;		
	for (i=0 ; i<n ; i++)
	{	
		for (j=0 ; j<m ; j++)
			cout << mat2[i][j]<< " ," ;
		cout << endl;
	}
 
	cout << "la matrice mat3 = \n" ;		
	for (i=0 ; i<n ; i++)
	{	
		for (j=0 ; j<m ; j++)
			cout << mat3[i][j]<< " ," ;
		cout << endl;
	}
 
	
	for (i=0 ; i<n ; i++)
		vc[i] = mat1[i][0];

	for (i=0 ; i<n ; i++)
		vl[i] = mat2[i][0];

	for (i=0 ; i<n ; i++)
		cout << "vc[" << i << "] = " << vc[i] ;

	for (i=0 ; i<n ; i++)
		cout << "vl[" << i << "] = " << vl[i] ;

}
