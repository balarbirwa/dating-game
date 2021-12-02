//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Compatability Class
#include <iostream>
#include <string>
#include "interests.h"
#ifndef Compatability_h
#define Compatability_h

using namespace std;

class Compatability
{
    //private
    private:
    int compatability;

    //public
    public:
    Compatability();
    Compatability(int);

    string toLower(string);

    //function to calculate compatability
    float calcCompatability(Interests, Interests);
};
#endif
