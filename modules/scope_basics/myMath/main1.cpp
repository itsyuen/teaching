// 2nd main program for practicing pointer and reference, and copy vs reference semantics

#include <iostream>   // iostream is actaully #included in myMath.h doesn't hurt to include again? always include the using ones
#include "myMath.h"

// The caller often looks the same. The function interface tells us the ownership/access semantics.
void myFuncVar(double);
void myFuncRef(double &);
void myFuncPtr(double *);

int main(){     // most underlining code

    std::cout << "As we are in main.\n";

    // using scalar to review pointer and reference
    double x = 5.0;     // simple double float declaration for a variable name
    double& y = x;      // y is an alias (non-independent) variable name directly linked to x

    double* ptr = &x;   // assigning a pointer to the get x's address, must de-ref ptr (*ptr) to be used!!!
    // pointer type must match the function parameter;
    // pointers can refer to scalars, arrays, objects, etc.

    std::cout << "The value of x is " << x << std::endl;
    std::cout << "The address of x is " << &x << std::endl;

    std::cout << "The value of y is " << y << std::endl;
    std::cout << "The address of y is " << &y << std::endl;

    std::cout << std::endl;

    y = 3;  // change x with alias y, 
            // however, alias are usually used with the interface of 
            // the called function sush as myFunc(float & someAlias){//...//}
    std::cout << "Using y= to re-assign y = x into: " << x << std::endl;
    std::cout << "We exercise passing both of them to a standard function calls: myFuncVar(x), and myFuncVar(y)" << std::endl;
    myFuncVar(x);   // this makes a local function copy
    myFuncVar(y);   // when we give an know alias, it's exactly giving the same variable 

    std::cout << std::endl;
   
    x = -8.371235;
    // since: double* ptr = &x (=&y)
    // then: ptr = &x (= &y))
    // and: *ptr = x (=y)
    std::cout << "We now re-assign x= (and y is changed as well) " << y << std::endl;     //  this changes y of course
    std::cout << "let's use pointer callbacks, since x and y has the same address , we pass the one pointer myFuncPtr(ptr):" << std::endl;
    myFuncPtr(ptr);
    std::cout << "If we have not pre-assign a double* ptr = &x, we can instantly call by pointer myFuncPtr(&y) or myFuncPtr(&x); " << std::endl;
    myFuncPtr(&x);
    myFuncPtr(&y);   // does work as expected

    std::cout << "\n";

    x = 2e33;
    std::cout << "Finally we re-re-assign x= " << x << std::endl;
    std::cout << "and use call by reference using both x and y (x's alias), which invokes a local 'antoehr alias'." << std::endl;

    myFuncRef(x);   // can argument in any variable, makes no copy, directly dealing with original input
    myFuncRef(y);   // this is inputing an known main alias, but since it is just another "linked" variable, it is rarely used this way

    std::cout << " \n" << std::endl;    // this makes double blank line

    // Read carefully the dummyMathPtr(double (*matrix)[3]) so now matrix[2][3] inside function is changing things like normal value call!!
    // use dymmyMathNo(const double name_of_variable) or dymmyMathNoNo(const double* name_of_pointer) to check permission
    // calling dummyMath function defined in myMath.h/myMath.cpp
    
    double some2by3Matrix[2][3] = {       // replacing rotationalMatrix[2][2] for practice
        {1,2,3},
        {4,5,6}
    };

    // double& matr[2][3]= some2by3Matrix;  // not correct syntax, this is an array OF references → illegal
    double (&matr)[2][3] = some2by3Matrix;  // note this is alias!!!

    some2by3Matrix[0][1] = -1.0;      // changing one of the some2by3Matrix element value through itself
    std::cout<< "change m(1,2) using reference into: " << matr[0][1] << std::endl;

    std::cout << "Before dummyMath(some2by3Matrix); :\n";
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << some2by3Matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    dummyMath(some2by3Matrix);      // standard way to call function(doubel array_argument)

    std::cout << "After dummyMath(some2by3Matrix); :\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    some2by3Matrix[0][0] = 1;
    some2by3Matrix[0][1] = 2;
    some2by3Matrix[0][2] = 3;
    some2by3Matrix[1][0] = 4;
    some2by3Matrix[1][1] = 5;
    some2by3Matrix[1][2] = 6;
    std::cout << "Let's reset some2by3Matrix = [1, 2, 3; 4, 5, 6]\n";

    // notice we've not assign a POINTER variable to store `some2by3Matrix's address...
    dummyMathPtr(some2by3Matrix);   // don't use dymmyMathPtr(&some2by3Matrix) it confuses the compiler
    //dummyMathPtr(& some2by3Matrix); // doesn't work
    // some2by3Matrix decays to: double (*)[3]
    // &some2by3Matrix has type: double (*)[2][3] // These are different pointer types.
    
    std::cout << "Cannot call dummyMathPtr(& some2by3Matix), use dummyMathPtr(some2by3Matrix); directly!!\n";
    std::cout << "After dummyMathPtr(some2by3Matrix); showing the changed some2by3Matrix:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << some2by3Matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // changing all of the some2by3Matrix element value through alias `matr`
    matr[0][0] = 2e3;
    matr[0][1] = 2e3;
    matr[0][2] = 3e3;
    matr[1][0] = 2e3;
    matr[1][1] = 2e3;
    matr[1][2] = 3e3;
    std::cout << "\nWe've reset matr = some2by3Matrix. \nAnd changing again using dummyMath(matr)\n";

    dummyMath(matr);

    std::cout << "After dummyMath(matr); showing some2by3Matrix:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << some2by3Matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n" << std::endl; // create double blank line

    // using different size matrices to verify none-size array callback: 2 by 3, 5 by 3 ,and 2 by 4  
    double A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    double B[5][3] = {};
    double C[2][4] = {};

    dummyMath(A);       // works
    dummyMath(B);       // ALSO works!

 std::cout << "After dummyMath(B); showing B:\n";

    for (int i = 0; i < 5; i++) {   // B is 5 by 3, showing all 5 rows
        for (int j = 0; j < 3; j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }

    dummyMathPtr(A);    // works
    dummyMathPtr(B);    // ALSO works

    dummyMathRef(A);    // works
    //dummyMathRef(B);    // compiler error

    //dummyMath(C);       // compiler error
    
    // Notice: raw arrays passed as function parameters are not copied.
    // The array parameter adjusts to a pointer-to-row.
    // An explicit array reference can preserve the exact dimensions.

    // end of program
    return 0;
}

// function definitions
void myFuncVar(double copied_value){
    std::cout << "we're in myFuncVar(double COPIED_VALUE) " << std::endl;
    std::cout << "argument COPIED_VALUE is of value: " << copied_value << std::endl;
    std::cout << "COPIED_VALUE's address is: "<< &copied_value << std::endl;
}

void myFuncPtr(double* pointer){
    std::cout << "we're in myFuncPtr(double* POINTER)" << std::endl;
    std::cout << "argument POINTER de-ref is of value: " << *pointer << std::endl;
    std::cout << "the address-value stored in POINTER is "<< pointer << std::endl;
}

void myFuncRef(double& local_ref){
    std::cout << "we're in myFuncRef(double& LOCAL_REF) " << std::endl;
    std::cout << "argument LOCAL_REF is of value: " << local_ref << std::endl;
    std::cout << "LOCAL_REF'S address is: "<< &local_ref << std::endl;
    std::cout << "Notice this is a call that functions similarity like POINTER call but is c++ style.\n";
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

//                   matrixA[2][3]    matrixB[5][3]    matrixC[2][4]
// dummyMath()             ✓                ✓                ✗
// dummyMathPtr()          ✓                ✓                ✗
// dummyMathRef()          ✓                ✗                ✗
