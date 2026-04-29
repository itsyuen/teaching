// robo.cpp
#include "robo2.h"
#include <iostream>

// constructor only require firstName, default gener=Gender::Unknown
Person::Person(const std::string& name): firstName(name){gender = Gender::Unknown;}

// setters
void Person::setFirstName(const std::string& name){
    this ->firstName = name;
}

void Person::setLastName(const std::string& name){
    this ->lastName = name;
}

void Person::setGender(const int& n){
    if (n == 0) gender = Gender::Male;
    if (n == 1) gender = Gender::Female;
    else gender = Gender::Unknown;
}

void Person::setDateOfBirth(const std::string& yyyy_mm_dd){
    bool c = isValidDate(yyyy_mm_dd);
    if (c == true){
        this ->dateOfBirth = yyyy_mm_dd;
    }
    else {
        std::cout << "not valid birth date, set to 2000-06-30\n";
        this ->dateOfBirth = "2000-06-30";
    }
    
}

// getters
const std::string Person::getFirstName() { return firstName; }
const std::string Person::getLastName() { return lastName; }
Gender Person::getGender() { return gender;}   // 
const int Person::getAge() { return 0; } // for now, later validation


bool Person::isValidDate(const std::string& s){
    // very light check: YYYY-MM-DD
    if (s.size() != 10) return false;
    return std::isdigit(s[0]) && std::isdigit(s[1]) &&
           std::isdigit(s[2]) && std::isdigit(s[3]) &&
           s[4] == '-' &&
           std::isdigit(s[5]) && std::isdigit(s[6]) &&
           s[7] == '-' &&
           std::isdigit(s[8]) && std::isdigit(s[9]);
}

std::string toString(Gender gender){
    if (gender == Gender::Male) return "male";
    if (gender == Gender::Female) return "female";
    else return "unknown";
}