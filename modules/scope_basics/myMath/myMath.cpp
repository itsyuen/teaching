#include <iostream>     // we see std::cout here...

#include "myMath.h"

// double rotationMatrix[2][2] = {      // standard 90 z axis rotation matrix de-precated for matrix[2][3] example
//     {0, -1},
//     {1, 0}
// };

void dummyMath(double matrix[2][3]){
     // we can change the value of the matrix, diliberatly changing only some of them
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
}

void dummyMathPtr(double (*matrix)[3]){
    // change the value of the matrix, diliberatly changing only some of them
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
}

void dummyMathRef(double (&matr)[2][3]){
    // do reference change with exact type raw array
    matr[0][0] = 0.0;
    matr[0][1] = -1.0;
    matr[1][0] = 1.0;
    matr[1][1] = 0.0;   // more rotation style, for future se3 use
}

//                   matrixA[2][3]    matrixB[5][3]    matrixC[2][4]

// dummyMath()             ✓                ✓                ✗
// dummyMathPtr()          ✓                ✓                ✗
// dummyMathRef()          ✓                ✗                ✗