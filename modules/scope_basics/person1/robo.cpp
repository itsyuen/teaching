// robo.cpp
#include "robo.h"
#include <iostream>

Person::Person(const std::string name): name(name){}

void RoboCopy(std::vector<Person> people){
    for (auto p: people){
        p.name = "Robo_" + p.name; // change visible to caller?
    }

    std::cout << "Inside RoboCopy:\n";
    for (auto p: people){
        std::cout <<"    "<< p.name << std::endl; // above change visible outside of for loop above?
    }
}

void RoboCopy_AutoRef(std::vector<Person> people){
    for (auto &p : people){
        p.name = "Robo_" + p.name; // chang visible to caller?
    }

    std::cout << "Inside RoboCopy_AutoRef:\n";
    for (auto p : people){
        std::cout << "    "<< p.name << std::endl; // above change visible outside of for loop?
    }
}

void RoboCopy_PersonPtr(std::vector<Person*> people){
    for (auto p : people){
        p->name = "Robo_" + p->name; // Is this change visible to the caller?    
    }
    std::cout << "Inside RoboCopy_PersonPtr:\n";
    for (auto p : people) {
        std::cout << "    " << p->name << std::endl; // Is the above change visible outside of the for loop above?
    }
}

void RoboCopy_AutoRef_PersonPtr(std::vector<Person*> people){
        for (auto &p : people){
        p->name = "Robo_" + p->name; // Is this change visible to the caller?
    }

    std::cout << "Inside RoboCopy_PersonPtr:\n";
    for (auto p : people) {
        std::cout << "    " << p->name << std::endl; // Is the above change visible outside of the for loop above?
    }

}