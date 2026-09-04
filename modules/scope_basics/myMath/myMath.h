#include <array>
#include <vector>       // will use later
#include <string>       // also later, maybe actually need only in main1

// personal math and pointer practice
extern double rotationMatrix[2][2];     // needed for main1 to see it. "extern" shows the body defined elsewhere

void dummyMath(double matrix[2][2]);    // needed for main1 to see, notice matrix "call by value"
// C-style array parameter; decays to pointer-to-row

void dummyMathPtr(double (*matrix)[2]); // actual body in myMath.cpp, notice matrix call by pointer
// explicitly written as pointer-to-row

