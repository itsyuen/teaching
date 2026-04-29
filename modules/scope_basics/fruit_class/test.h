#pragma once

#include <string>
#include <cstdint>

namespace demo {

    struct ColorCode{
        uint8_t r;
        uint8_t g;
        uint8_t b;

        std::string name;
        
        int mixColor(const std::string& a, const std::string& b);

    };

    class Fruit {
    public:
        Fruit(std::string name, double w, std::string c);

        double getWeight() const;
        const std::string& getColor() const;
        const std::string& getName() const;

        void setWeight(double a);
        void setColor(std::string c);
        void setName(std::string name);
    
    private:
        double weight;
        std::string color;
        std::string fruitname;

    };

    // free functions (outside of class)
    int compareFruitByWeight(const Fruit& a, const Fruit& b);
    int mixFruitByColor(const Fruit& a, const Fruit& b);

}   // namespace demo