//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Interests Class
#include "interests.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Interests::Interests()
{
    creativity = "";
    sports = "";
    food = "";
    hobby ="";
    music = "";
}

//parameterized constructor
Interests::Interests(string c, string s, string f, string h, string m)
{
    creativity = c;
    sports = s;
    food = f;
    hobby = h;
    music = m;

}
//getters
string Interests::getCreativity()
{
    return creativity;
}
string Interests::getSports()
{
    return sports;
}
string Interests::getFood()
{
    return food;
}
string Interests::getHobby()
{
    return hobby;
}
string Interests::getMusic()
{
    return music;
}

//setters
void Interests::setCreativity(string c)
{
    creativity = c;
}
void Interests::setSports(string s)
{
    sports = s;    
}
void Interests::setFood(string f)
{
    food = f;
}
void Interests::setHobby(string h)
{
    hobby= h;
}
void Interests::setMusic(string m)
{
    music = m;
}
