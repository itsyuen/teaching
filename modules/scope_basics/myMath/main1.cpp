// 2nd main program for practicing pointer and reference, and copy vs reference semantics

#include <iostream>   // iostream is actaully #included in myMath.h doesn't hurt to include again? always include the using ones
#include "myMath.h"

int main(){     // most underlining code

    // calling dummyMath function defined in myMath.h/myMath.cpp
    std::cout << "As we are in main.\n";
    
    std::cout << "Before dummyMath():\n";
    

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << rotationMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    dummyMath(rotationMatrix);

    std::cout << "After dummyMath():\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << rotationMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // end of program
    return 0;
}
 
// better move to myMath.cpp
// void dummyMath(double matrix[2][2]){         
//     std::cout << "inside dummyMath: " << std::endl;
//     for (int i = 0; i < 2; i++){
//         for (int j = 0; j < 2; j++){
//             std::cout << matrix[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     // change the value of the matrix
//     matrix[0][0] = 1;
//     matrix[0][1] = 0;
//     matrix[1][0] = 0;
//     matrix[1][1] = 1;
// }
