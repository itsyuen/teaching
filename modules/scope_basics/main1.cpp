// 2nd main program for practicing pointer and reference, and copy vs reference semantics

#include <iostream>
#include "myMath.h"



int main(){
    dummyMath(rotationMatrix);
    return 0;

}
 

 void dummyMath(double matrix[2][2]){
    std::cout << "inside dummyMath: " << std::endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // change the value of the matrix
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
}
