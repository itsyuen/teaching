#include <array>
#include <vector>       // will use later
#include <string>       // also later, maybe actually need only in main1

// personal math and pointer practice
//extern double rotationMatrix[2][2];     // needed for main1 to see it. "extern" shows the body defined elsewhere
// de-precated for better float matrix[2][3] exercise, so is the internal of dummyMath changes

void dummyMath(double matrix[2][3]);    // needed for main1 to see, notice matrix "call by value"
// C-style array parameter; decays to pointer-to-row
// Looks like a 2x3 array parameter,
// but adjusts to: double (*matrix)[3]

void dummyMathPtr(double (*matrix)[3]); // actual body in myMath.cpp, notice matrix call by pointer
// explicitly written as pointer-to-row, accepts unknow number of row, same as previous call 

void dummyMathRef(double (&matr)[2][3]);    // method body in myMath.cpp, make reference in body without knowing which function call argument is comming
// C++ reference to the complete 2x3 array type.
// Both dimensions are preserved. 
