/* The Matrix class Header (Matrix.h) */
#ifndef MATRIX_H   // Include this "block" only if MaATRIX_H is NOT defined
#define MATRIX_H   // Upon the first inclusion, define TIME_H so that
                 //  this header will not get included more than once
                 
#include <iostream> //using cout
#include <vector> //using vector
#include <stdio.h>

using namespace std;
typedef vector<vector<double> > Dmatrix; //For making things tidier

// Circle class declaration
class Matrix
{
	private:  // Accessible by members of this class only
   // private data member (variable)
		Dmatrix main;
		int Findmax() const;
		
	public: // Accessible by ALL
   // Declare prototype of member functions
   
   //Constructor
	Matrix(Dmatrix temp=Dmatrix (0,vector<double>(0,0) ));
	
   // Public getter & settes for private data member
   	Dmatrix getM() const;
	void setM(Dmatrix A);

	 // Public member Functions
	int getcol() const;
	int getrow() const;	
	void printM() const;
	Dmatrix decrement(Dmatrix Z) const;
	Dmatrix multi(Dmatrix multiplayer) const;
	Dmatrix multicons(double c) const;
	Dmatrix transpose() const;
	void norm(double &eigenvalue);
		
};
#endif //Matrix_H
