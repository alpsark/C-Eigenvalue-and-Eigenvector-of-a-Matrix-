#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include "Matrix.h" //Matrix class

using namespace std;
typedef vector<vector<double> > Dmatrix; //For making things tidier

// Function prototypes
int chkfile(int argc,char* argv[]) ;
Dmatrix crtmatrix(string filename);
Dmatrix Randvector(int size);
Dmatrix Findevec(Matrix A,double &eval,double tol);
Matrix Deflation(Matrix A,Matrix x,double eval,double tol);

//MAIN FUNCTION
int main (int argc,char* argv[]){
	if 	(chkfile(argc,argv)){	return -1 ;} //Checks the files entered correctly(Exits if they are not)
	
	double toler,eval,eval2; //Define tolerance and Eigenvalues
	Matrix A(crtmatrix(argv[1]));
	if(A.getM().empty()){return -1;	} //Clase the program if A matrix is empty
	
	A.printM();//Print the matrix
	cout << endl;
	
	stringstream stream(argv[2]);
	stream >> toler; //take tolerance	
	Dmatrix evec= Findevec(A,eval,toler);//Find Eigenvector
	
	cout <<  "Eigenvalue#1: " << eval << endl;	  
    ofstream solution (argv[3]);   

    solution <<  "Eigenvalue#1: " << eval << endl; 
	for(int n=0;n<evec.size();n++){
		cout << evec[n][0] << endl;
		solution << evec[n][0] << endl;
	}
	Matrix defmat=Deflation(A,evec,eval,1e-3);
	
    Findevec(defmat,eval2,1e-3);
	solution <<  "Eigenvalue#2: " << eval2 << endl;
	cout <<  "Eigenvalue#2: " << eval2 << endl;
	solution.close();
	return 0;
}
// Function definitions

//Function that checks the files are entered correctly
int chkfile(int argc,char* argv[]){ 
	if(argc=4){
		cout << "argv[1] = " << argv[1] << endl;
		cout << "argv[2] = " << argv[2] << endl;
		cout << "argv[3] = " << argv[3] << endl;
		//You should see :
		// argv[1] = A.txt
		// argv[2] = Tolerance
		// argv[3] = Name of the output file
		//if you did everything correctly
		return 0;
	}
	else{
		cout << "Missing one or more arguments.Exiting...";
		return 1;
	}
}
//Read matrix from data
Dmatrix crtmatrix(string filename){
		ifstream file(filename.c_str());//input file stream to open the filename
		Dmatrix M;
		// Check the file is opened properly
		if(file.is_open() && file.good())  { 
		cout << filename << " is open.\n" ;
		}
		else{ 
		cout << filename << " is failed to open.\n" ; 			
		return M;}

		string line;
		double element;
		vector<double> v;
		while(getline(file,line)){
			stringstream stream(line);		
			while(1){
				stream >> element ;
				if(!stream){break;}
				//Dynamic allocation
				v.push_back(element);
			}
			M.push_back(v);
			v.clear();
		}
		return M;
}
//Create randomized vector
Dmatrix Randvector(int size){

	vector<double> Myvector(1);
	Dmatrix vector;
	 /* initialize random seed: */
	srand(time(NULL)); 		
	for(int i=0;i<size;i++){
		/* generate random number between 0 and 1.999 */
		double x = rand() %1999;
        x= x/1000;
        
        Myvector[0]=x;
        vector.push_back(Myvector);
    }
    return vector;
}
//Find Eigenvector
Dmatrix Findevec(Matrix A,double &eval,double tol){
		double lambda;
		double lambdaOld=-1000;		
		
		Matrix x(Randvector(A.getcol()));
		x.norm(lambda);
		
		Matrix xnew;
	while(fabs((lambda - lambdaOld)/lambda) > tol ){
		lambdaOld=lambda;
		xnew.setM(A.multi(x.getM()));
		x=xnew;		
		x.norm(lambda);
	}
	eval = lambda;
	return x.getM();
}
//Find deflation matrix
Matrix Deflation(Matrix A,Matrix x,double eval,double tol){
	Matrix Z(A.transpose());
	
	double dummy;
	
	Matrix y(Findevec(Z,dummy,tol));//Find left Eigenvector
	Matrix ytrans(y.transpose());//Take its tranpose	
	Dmatrix norm=ytrans.multi(x.getM());	
	y.setM(y.multicons(eval/norm[0][0]));//Normalize it
	Z.setM(x.multi(y.transpose()));//Find x*u(transpose)
	A.setM(A.decrement(Z.getM())); //Subtract from A
	return A;
}
	
