//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Profile Class
#include <iostream>
#include <string>
#ifndef Profile_h
#define Profile_h
// #include "interests.h"
// #include "Person.h"
using namespace std;

class Profile
{
    private:
    //string name;
    int age;
    int height;
    string gender;
    string sign;
    string job;

    public:
    //constructors
    Profile();
    Profile(int a, int h, string g, string ss, string j);

    //getters
    //string getName();
    int getAge();
    int getHeight();
    string getGender();
    string getStarSign();
    string getJob();

    //setters
    //void setName(string n);
    void setJob(string j);
    void setAge(int a);
    void setHeight(int h);
    void setGender(string g);
    void setStarSign(string ss);

};
#endif
