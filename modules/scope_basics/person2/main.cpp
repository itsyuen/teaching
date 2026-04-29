// mian program for starting all objects for runtime execution.

#include "robo2.h"
#include <iostream>


int main(){
    std::cout << "Running main!" << std::endl;
    // test Robo_ copy 
    std::vector<Person> team{
        Person("Alice"),
        Person("Bianca"),
        Person("Caitlyn")
    };

    std::vector<Person*> teamPtr {&team[0], &team[1], &team[2]};

    for (auto & p: team){
        std::cout << "    " << p.getFirstName() << std::endl;
    }
    
    std::cout << "Please input a Lastname\n";
    std::string lastname;
    std::cin >> lastname;

    for (auto &p : team){
        p.setLastName(lastname);
        std::cout << "New names are: " << p.getFirstName() << " " << p.getLastName() << std::endl; 
    }

    std::cout << "Gender without setting, only by constructing.\n";
    std::cout << teamPtr[1] -> getFirstName() << "'s gender is: " << toString(team[1].getGender()) << std::endl;
    std::cout << team[0].getAge() << std::endl;
    //std::cout << teamPtr[2] ->getGender() << std::endl;
    
    std::cout << team.size() << std::endl;
    
    return 0;

}





