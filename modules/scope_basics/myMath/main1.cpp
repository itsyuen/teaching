// 2nd main program for practicing pointer and reference, and copy vs reference semantics

#include <iostream>   // iostream is actaully #included in myMath.h doesn't hurt to include again? always include the using ones
#include "myMath.h"

// The caller often looks the same. The function interface tells us the ownership/access semantics.

int main(){     // most underlining code

    double x = 5.0;     // simple double float declaration for a variable name
    double& y = x;      // y is an alias (non-independent) variable name linked to x

    double* ptr = &x;   // assigning a pointer to the get x's address, must de-ref ptr (*ptr) to be used!!!
    // read carefully the dummyMathPtr(double (*matrix)[2]) so now matrix[2][2] inside function is changing things like normal value call!!

    // use dymmyMathNo(const double name_of_variable) or dymmyMathNoNo(const double* name_of_pointer) to check permission

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
    // dummyMath(& rotationMatrix);         // wrong way to call, this is & is for passing ptr variables

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
