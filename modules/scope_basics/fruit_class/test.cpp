// my restart cpp program

#include <iostream>
#include "test.h"
#include <array>

//using namespace std; this is used in .h headers?

namespace demo {
    ColorCode red{246, 0, 0, "red"};
    ColorCode orange{255, 140, 0, "orange"};
    ColorCode yellow{255, 238, 0, "yellow"};
    ColorCode green{77, 233, 0, "green"};
    ColorCode blue{0, 0, 255,"blue"};
    ColorCode violet{72, 21, 170, "violet"};

    std::array <const ColorCode, 6> colors = {
        red, orange, yellow, green, blue, violet
    };
    
    std::array <const ColorCode*, 6> colors_ptr {
        &red, &orange, &yellow, &green, &blue, &violet
    };
    
// made a sturct (public class for data strorage)
    int ColorCode::mixColor(const std::string& a, const std::string& b){
        std::cout << "Reciving 1st color: " << a << std::endl;
        std::cout << "Reciving 2st color: " << b << std::endl;

        // read basic ColorCode as an array 
        for (const auto& c : colors){
            std::cout << c.name << ": ("
                      << int(c.r) << ", "
                      << int(c.g) << ", "
                      << int(c.b) << ")\n";
        }
        
        // comapre input name with pointers array
        for (const auto p: colors_ptr){
            if (p && p-> name == a) {
                std::cout << a << " is found\n";
            }
            else if (p && p-> name == b){
                std::cout << b << " is found\n";
            }
        };
        
        return 0;
    };

 
// make a fruit class and some array structures
// use std::library of array kind to make sure
// use pointers to practice using a full object to compare apples and oranges.

    Fruit::Fruit(std::string name, double w, std::string c)
        : fruitname(std::move(name)), weight(w), color(std::move(c)) {}

    double Fruit::getWeight() const {return weight;}

    const std::string& Fruit::getColor() const {return color;}

    const std::string& Fruit::getName() const {return fruitname;}

    void Fruit::setWeight(double a) { weight = a; }

    void Fruit::setColor(std::string c) { color = std::move(c); }

    void Fruit::setName(std::string name) { fruitname = std::move(name); }

    int compareFruitByWeight(const Fruit& a, const Fruit& b) {
        std::cout << "comparing " << a.getName()  << " vs " << b.getName() << std::endl;
        if (a.getWeight() < b.getWeight()) {
            std::cout << a.getName() << " is lighter!" << std::endl;
            return -1;
        }
        else if (a.getWeight() > b.getWeight()) {
            std::cout << b.getName() << " is lighter!" << std::endl;
            return 1;
        }
        return 0;
    }

    int mixFruitByColor(const Fruit& a, const Fruit& b) {
/*      
        std::cout << "first fruit is: " << std::endl;
        std::cout << a.getColor() << std::endl;
        std::cout << "second fruit is: " << std::endl;
        std::cout << b.getColor() << std::endl;
 */        
        // call ColorCode mixing function first by making a "mixer" ColorCode object
        ColorCode mixer;
        mixer.mixColor(a.getColor(), b.getColor());

        return 0;
    }
}
