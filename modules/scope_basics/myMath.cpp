#include "myMath.h"

double rotationMatrix[2][2] = {{0, -1}, {1, 0}}; // 90 degree rotation matrix

void dummyMathPtr(doubel (*matrix)[2]){
    std::cout << "inside dummyMathPtr: " << std::endl;
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