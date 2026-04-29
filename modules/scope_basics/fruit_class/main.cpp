// fruit practice
#include <iostream>
#include <vector>
#include <string>

#include "test.h"

int main(){
    demo::Fruit apple("apple", 0.2, "red");
   
    demo::Fruit orange("orange", 0.25, "orange");
    
    int r = demo::compareFruitByWeight(apple, orange);

    //std::cout << r <<std::endl;
    
    demo::Fruit banana("banana", 0.125, "yellow");
   
    r = demo::compareFruitByWeight(banana, orange);
    
    demo::mixFruitByColor(banana, apple);

    return 0;
}