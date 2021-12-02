//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Person Class
#include <iostream>
#include <string>
#ifndef Person_h
#define Person_h
#include "profile.h"
#include "interests.h"
// #include "profile.cpp"
// #include "interests.cpp"
using namespace std;

class Person
{
    private:
    string name;
    int id;
    Profile PersonProfile;
    Interests PersonInterests;
    
    public:
    //constructors
    Person();
    Person(string n, Profile PersonProfile, Interests PersonInterests);

    //getter and setter for profile
    Profile getPersonProfile();
    void setPersonProfile(int age, int height, string gender, string sign, string job);

    //getter and setter for interests
    Interests getPersonInterests();
    void setPersonInterests(string creativity, string sports, string food, string hobby, string music);

    //getter and setter for name
    string getName();
    void setName(string n);

};
#endif
