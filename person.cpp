//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Person Class
#include "person.h"
// #include "profile.h"
// #include "interests.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor
Person::Person()
{
    name = "";
    //row=-1;
    //col=-1;
    PersonProfile = Profile(0, 0, "", "", "");
    PersonInterests = Interests("", "", "", "","");
}
//parameterized constructor
Person::Person(string n, Profile pp, Interests pi)
{
    name = n;
    //row = x;
    //col = y; 
    PersonProfile = pp;
    PersonInterests = pi;
}

Profile Person::getPersonProfile()
{
    return PersonProfile;
}
//setter that calls profile class
void Person::setPersonProfile(int age, int height, string gender, string sign, string job)
{
    PersonProfile.setAge(age);
    //PersonProfile.row(x);
    //PersonProfile.col(y);
    PersonProfile.setHeight(height);
    PersonProfile.setGender(gender);
    PersonProfile.setStarSign(sign);
    PersonProfile.setJob(job);
    //PersonProfile = Profile(age, height, gender, sign, job);
}

Interests Person::getPersonInterests()
{
    return PersonInterests;
}
//setter that calls interest class
void Person::setPersonInterests(string creativity, string sports, string food, string hobby, string music)
{
    PersonInterests.setCreativity(creativity);
    PersonInterests.setSports(sports);
    PersonInterests.setFood(food);
    PersonInterests.setHobby(hobby);
    PersonInterests.setMusic(music);
    //PersonInterests = Interests(creativity, sports, food, hobby, music);  
}

//name getters and setter
string Person::getName()
{
    return name;
}
void Person::setName(string n)
{
    name = n;
}
