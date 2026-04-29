// robo.h

#pragma once
#include <vector>
#include <string>

class Person {
    public:
    std::string name;
    Person(const std::string name);

};

void RoboCopy(std::vector<Person> people);

void RoboCopy_AutoRef(std::vector<Person> people);

void RoboCopy_PersonPtr(std::vector<Person*> people);

void RoboCopy_AutoRef_PersonPtr(std::vector<Person*> people);


