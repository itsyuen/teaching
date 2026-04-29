// robo2.h

#pragma once
#include <vector>
#include <string>

// an enumerated class/structure..
enum class Gender {
    Male,       // Gender::Male
    Female,     // Gender::Female
    Unknown     // Gender::Unknown
};

class Person {  // firstName, lastName, gender(enum), dateOfBirth(string)
public:
    Person(const std::string& firstName); // only need a first name for constructor

    // optinal enrichments setters
    void setFirstName(const std::string& fname);
    void setLastName(const std::string& lname);
    void setGender(const int& n);   // prompt before call 0~2
    void setDateOfBirth(const std::string& yyyy_mm_dd); // prompt string specification

    // accessors getters
    const std::string getFirstName();
    const std::string getLastName();
    Gender getGender();
    const int getAge();

private:
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    Gender gender;

    bool isValidDate(const std::string& s);

};

std::string toString(Gender gender);


