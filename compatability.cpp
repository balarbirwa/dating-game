#include <iostream>
#include "compatability.h"
#include "interests.h"
#include <string>
#include <cmath>
#define MAXINTEREST 5

using namespace std;



//default constructor
Compatability::Compatability()
{
    int compatability = 0;
}
//parameterized constructor
Compatability::Compatability(int c)
{
    compatability = c;
}

string Compatability::toLower(string lower)
    {
        int size = lower.length();
        for(int i = 0; i < size; i ++)
        {
            if (lower[i] >= 65 && lower[i] <= 90)
            {
                lower[i] = lower[i] + 32;
            }
        }
        return lower;
    }

float Compatability::calcCompatability(Interests currentPersonInterest, Interests currentPositionInterest)
{

    //int const MAXINTEREST = 5;
    int interestcal=0;
    float rvalue=0;

    //cout <<"CP "<<currentPersonInterest.getCreativity()<<" ";
    //cout <<"CPo "<<currentPositionInterest.getCreativity()<<" " << endl;

    //cout <<"CP "<<currentPersonInterest.getMusic()<<" ";
    //cout <<"CPo "<<currentPositionInterest.getMusic()<<" "<< endl;

    //each compares each interets with interests object of person interest and position interest
    if(toLower(currentPersonInterest.getCreativity()) == toLower(currentPositionInterest.getCreativity()))
    {
        //cout<<"1 ";
        interestcal = interestcal+1;
    }
    if(toLower(currentPersonInterest.getMusic()) == toLower(currentPositionInterest.getMusic()))
    {
        //cout<<"2 ";
        interestcal = interestcal+1;
    }
    if(toLower(currentPersonInterest.getHobby()) == toLower(currentPositionInterest.getHobby()))
    {
        //cout<<"3 ";
        interestcal = interestcal+1;
    }
    if(toLower(currentPersonInterest.getSports()) == toLower(currentPositionInterest.getSports()))
    {
        //cout<<"4 ";
        interestcal = interestcal+1;
    }
    if(toLower(currentPersonInterest.getFood()) == toLower(currentPositionInterest.getFood()))
    {
        //cout<<"5 ";
        interestcal = interestcal+1;
    }

    //cout<<"intcal "<< interestcal <<endl;

    //equation for calculting compatability
    rvalue = float((interestcal * 100) / MAXINTEREST);

    //cout <<"rvalue " << rvalue << endl;
    //rvalue = (rvalue * 100);
    //cout <<"Return " <<rvalue << endl;
    return rvalue;

    //return compatability;
}
