//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Interests Class
#include <iostream>
#include <string>
#ifndef Interests_h
#define Interests_h
using namespace std;

class Interests
{
    private:
    string creativity;
    string sports;
    string food;
    string hobby;
    string music;

    public:
    //constructors
    Interests();
    Interests(string c, string s, string f, string h, string m);
    //getters
    string getCreativity();
    string getSports();
    string getFood();
    string getHobby();
    string getMusic();

    //setters
    void setCreativity(string);
    void setSports(string);
    void setFood(string);
    void setHobby(string);
    void setMusic(string);
};
#endif
