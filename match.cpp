//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Match Class
#include <iostream>
#include <string>
#include "match.h"
#include "compatability.h"
#include "person.h"
using namespace std;


bool Match::setMatch(int compatability)
{
    //helper variables
    int dbcount=0;
    int temppos=0;
    int MAXDB = 16;
    Person PersonDatabase[MAXDB];
    Compatability tempCompatibility;
    int option;
    //DBlocation = CurrentMap.isOptionLocation();
   
   //asks user who they want to test compatability with
    cout << "Which profile on the map would you like to match with?" << endl;
    cin >> temppos;
    //equation for compatability
    compatability = tempCompatibility.calcCompatability(PersonDatabase[dbcount-1].getPersonInterests(), PersonDatabase[temppos].getPersonInterests());
    cout << "Here is your compatability with this person: " << compatability << endl;
    cout << "Would you like to match with this person?" << endl;
    cout << "Type 1 for yes and 0 for no." << endl;
    cin >> option;
    if(option == 1)
    {
        //int compatability = tempCompatibility.calcCompatability(PersonDatabase[dbcount-1].getPersonInterests(), PersonDatabase[temppos].getPersonInterests());
        //if compatability is above 70 
        if(compatability > 70)
        {
            //prints its a match and ends the game
            cout << "ITS A MATCH!" << endl;
            cout << "You are now in love, have a wonderful life together!" << endl;
            cout << endl;
            //bool returns true
            return true;
        }
        else
        {
            //print for low compatability
            cout << "Looks like your compatability is low, it is not a match" << endl;
            // cout << "They may not want to match with you." << endl;
            //bool returns false
            return false;
        }
    }
    else if (option == 0)
    {
        //prints they didnt select to match
        cout << "You did not select to match" << endl;
        //bool returns false
        return false;
    }
    else
    {
        //invalid input
        cout << "Invalid input." << endl;
    }

    return false;
}
