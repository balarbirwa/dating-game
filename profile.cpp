//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Profile Class
#include "profile.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Profile::Profile()
{
    //name = "";
    job = "";
    age = 0;
    height = 0;
    gender = "";
    sign = "";

}
//parameterized construtor
Profile::Profile(int a, int h, string g, string ss, string j)
{
    //name = n;
    job = j;
    age = a;
    height = h;
    gender = g;
    sign = ss;
}

//getters
//string Profile::getName()
//{
//  return name;
//}

//getters
int Profile::getAge()
{
    return age;
}
int Profile::getHeight()
{
    return height;
}
string Profile::getGender()
{
    return gender;
}
string Profile::getStarSign()
{
    return sign;
}
string Profile::getJob()
{
    return job;
}

//setters
//void Profile::setName(string n)
//{
//    name = n;
//}

//setters
void Profile::setJob(string j)
{
    job = j;
}
void Profile::setAge(int a)
{
    age = a;
}
void Profile::setHeight(int h)
{
    height = h;
}
void Profile::setGender(string g)
{
    gender = g;
}
void Profile::setStarSign(string ss)
{
    sign = ss;
}
