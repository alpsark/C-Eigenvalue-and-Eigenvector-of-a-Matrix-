# C-Eigenvalue-and-Eigenvector-of-a-Matrix-
Written in C++
Computing Eigenvalues and Eigenvectors using Normalized Power Iteration together with Deflation 

This program gives the result of 2 dominant Eigenvalues and first eigenevector and prints them to given txt

There may be more than one eigenvalue having same (maximum) modulus, in which case iteration may converge to linear combination of corresponding eigenvectors.


Command line arguments:

1. Search cmd.exe (It should be in C:\Windows\System32)

2. Go to .cpp directory

3. Type " g++ -o (exe_name) main.cpp Matrix.cpp " to command line

4. Type " (exe_name) (matrix).txt (tolerance) (output).txt " to command line

5. If everything done correctly you should see   
argv[1] = A.txt  
argv[2] = (tolerance)  
argv[3] = (output).txt  
A.txt is open.    

       13 5  
       2 4                                           <-----A matrix

       Eigenvalue#1:  14  
       1		                                         	<-----Solution  
       0.2  
       Eigenvalue#2: 3
