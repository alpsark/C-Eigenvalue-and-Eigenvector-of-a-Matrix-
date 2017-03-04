/* The Matrix class Implementation (Matrix.cpp) */

#include "Matrix.h" // user-defined header in the same directory
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h> //using abs value

using namespace std;
typedef vector<vector<double> > Dmatrix; //For making things tidier

// Constructor
Matrix::Matrix(Dmatrix temp) {
		main=temp;
}

// Public getter for private data member main
Dmatrix  Matrix::getM() const{
	return main;
}
//Find index of inf-norm
int Matrix::Findmax() const{
	double a=fabs(main[0][0]);
	int idx=0;
	for(unsigned i=0;i<main.size();i++){
		if(a<fabs(main[i][0])){
			a=fabs(main[i][0]);
			idx=i;
		}
	}
	return idx;
}
// Public setter for private data member main
void  Matrix::setM(Dmatrix A) {
	main=A;
}
//get number of columns
int Matrix::getcol() const{
	return int(main.at(0).size());
}
//get number of rows
int Matrix::getrow() const{
	return int(main.size());
}
//print the matrix
void Matrix::printM() const{
	for(int i=0;i<main.size();i++){
		for(int j=0;j<main[0].size();j++){
			cout << main[i][j] << " ";
			
		}
		cout << endl ;
	}
}
//Subrtraction of Z from main
Dmatrix Matrix::decrement(Dmatrix Z) const{
	Dmatrix D;
	vector<double> vec;
	for(unsigned i=0;i<main.size();i++){
		for(unsigned j=0;j<main[0].size();j++){
			vec.push_back(main[i][j]-Z[i][j]);
		}
		D.push_back(vec);
		vec.clear();
	}
	return D;
}
//multiplication of main*multiplayer
Dmatrix Matrix::multi(Dmatrix multiplayer) const{
	Dmatrix D;
	vector<double> vec;
	double K=0;
	for(unsigned i=0;i<main.size();i++){
		for(unsigned j=0;j<multiplayer[0].size();j++){ 
			for(unsigned c=0;c<multiplayer.size();c++){
				K += main[i][c]*multiplayer[c][j];
			}
			vec.push_back(K);
			K=0;
		}
		D.push_back(vec);
		vec.clear();
	}
	return D;
}
//Multiplication with some constant
Dmatrix Matrix::multicons(double c) const{
	Dmatrix D;
	vector<double> vec;
	for(unsigned i=0;i<main.size();i++){
		for(unsigned j=0;j<main[0].size();j++){
			vec.push_back(main[i][j]*c);
		}
		D.push_back(vec);
		vec.clear();
	}
	return D;
}
//Take transpose
Dmatrix Matrix::transpose() const{
	Dmatrix D;
	vector<double> vec;
	for(int i=0;i<main[0].size();i++){
		for(int j=0;j<main.size();j++){
			vec.push_back(main[j][i]);
		}
		D.push_back(vec);
		vec.clear();
	}
	return D;
}
//inf-norm
void Matrix::norm(double &eigenvalue){
	
	int maxind=Findmax();
	Dmatrix D;
	vector<double> vec(1,1);
	
	for(int i=0;i<main.size();i++){
		vec[0]=(main[i][0]/fabs(main[maxind][0]));			
		D.push_back(vec);
	}
	eigenvalue=main[maxind][0];
	main=D;	
}
