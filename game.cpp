#include <iostream>
#include <string>
#include <fstream>
//#include "person.cpp"
#include "person.h"
#include <stdlib.h>
//#include "interests.cpp"
#include "interests.h"
//#include "profile.cpp"
#include "profile.h"
//#include "map.cpp"
#include "map.h"
//#include "match.cpp"
#include "match.h"
// #include "compatability.cpp"
#include "compatability.h"


#define MAXDB 16
int SearchDB (string, Person[]);

using namespace std;

/*
split function that takes a string and splits it into an array by every delimiter, in this case, a comma.
the parameters are the string, the seperator, string array, and size of array
returns the number of delimiters
*/

int split(string s, char seperator, string s_array[], int size)
{
    int num_delimiter = 0; //initialize the variable for number of delimiters
    int str_size = s.length(); //define size as the lenth of the string s
    string temp; 

    if (str_size != 0)
    {
            for (int i = 0; i < str_size; i++) //traverse through the string
            {
                char character = s[i]; //define character as a single character in the string
                if (character == seperator) //if charcter is equal to seperator (delimiter)
                {
                    s_array[num_delimiter] = temp; 
                    num_delimiter++;
                    temp = "";
                }
                else 
                {
                    temp = temp + s[i]; //adding the non-delimiter character
                }   
                s_array[num_delimiter] = temp; //finishes the string in array
            }
            num_delimiter ++;
        
        if (size < num_delimiter) //ensures correct size
        {
            return -1;
        }
        else
        {
            return num_delimiter;
        }
    }
    else if (str_size == 0)
    {
        return 0;
    }
    return num_delimiter;
   
}

/*
this is the main game function that includes the game menu and calls the split and reads the profile.txt file 
no parameters
return 0 
*/

int main()
{
    //initialize all the variables
    string option;
    int num=0;
    int position=0;
    Person PersonDatabase[MAXDB];
    Profile tempPersonProfile;
    Interests tempPersonInterest;
    Person tempPersonDetail;
    string personname;
    int personage=0;
    string personheight;
    string persongender;
    string personsign;
    string personjob;
    string personcreativity;
    string personsports;
    string personfood;
    string personhobby;
    string personmusic;
    string line;
    string temp[11];
    int dbcount=0;
    int firsttime = 0;
    Interests PersonInterest;
    int DBlocation=0;
    float CompValue=0;
    int temppos=0;
    Map CurrentMap;
    Compatability tempCompatibility;
    
    //this section is to read the profile.txt file and assign it to the person database array 
    ifstream in1("profile.txt");
    if(in1.fail())
    {
        return -1;
        cout<< "Unable to open profile database file" <<endl;
    }
    else
    {
        //while loop until end of file
        while(!in1.eof())
        {
            //getline for each line, which is one person
            getline(in1, line);
            if(line.length() > 0)
            {
                //calling the split function and using the return value of the function 
                int ret=0;
                
                ret = split(line, ',', temp, 10);
                //PersonDatabase[].setName(personname);
                // cout << temp[0];
                // cout << temp[1];
                // cout << temp[2];
                // cout << temp[3];
                // cout << temp[4];
                // cout << temp[5];
                
                //assigns the name to index 0 of temp array
                PersonDatabase[dbcount].setName(temp[0]);
                //assigns the profile using setters  to index 1-5
                PersonDatabase[dbcount].setPersonProfile(stoi(temp[1]), stoi(temp[2]), temp[3], temp[4], temp[5]);

                //assigns the interests to index 6-10 of temp array
                personcreativity = temp[6];
                personsports = temp[7];
                personfood = temp[8];
                personhobby = temp[9];
                personmusic = temp[10];

                //then sets the interests in class with the setter
                PersonDatabase[dbcount].setPersonInterests(personcreativity, personsports, personfood, personhobby, personmusic);
                dbcount++;
            }
        }

    }

    //this next chunk of couts prints the welcome to game and brief inrtsuctions
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << ">>>>>>>>Hello! Welcome to Love City!<<<<<<<<" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;

    cout << "Looking for love? Here are some instructions on how to play." << endl;
    cout << "First you will be asked your name, then a menu will be printed. You will want to choose option 1 to set up your profile." << endl;
    cout << "You will need to enter your basic information as well as some of your interests to calculate compatability." << endl;
    cout << "You can then choose to move on the map, open a potential love match profiles, test compatability, and match with someone." << endl;
    cout << "The numbers on the map are potential love candidates that you can navigate to in order to see your compatability with that person." << endl;
    cout << "Once you've found a match the game will end. You can quit if you feel you will never find love." << endl;
    cout << endl;

    //prompts user input if they want to play the game
    cout << "Do you want to find a match?" << endl;
    cout << "Type 1 to start or 0 to quit." << endl;
    cin >> num;


    if(num == 1)
    {
        //prompts user input for name
        cout << "Great! Lets get started. Enter your name." << endl;
        cin >> personname;
        cout << "Lovely name!" << endl;
        cout << endl;
        //bool value for while loop
        bool KeepGoing =1;
        while(KeepGoing)
        {
            // PersonDetail.setAge(person1)
            // if (dbcount>0)
            // {
            //     cout << "Enter name. " << endl;
            //     cin >> personname;
            //     cout << "Nice!!" << endl;
            // }
            // //menu will be here
            // position = SearchDB(personname, PersonDatabase);
            // if(position>=0)
            // {
            //     cout << "Your profile already exist" << endl;
            //     cout << "Select another numerical option:" << endl;
            // }
            // else
            // {
            //     cout << "Select a numerical option:" << endl;
            // }

            //menu 
            cout << "Select a numerical option:" << endl;
            cout << "======Main Menu=====" << endl;
            cout << "1. Set up Profile" << endl;
            cout << "2. Move on Map" << endl;
            cout << "3. Open a Person's Profile on the Map" << endl;
            cout << "4. Test Compatability" << endl;
            cout << "5. Like what you see? Select Match" << endl;
            cout << "6. You found love? Quit." << endl;

            //user input for option of menu
            cin >> option;
            num = stoi(option);

                //switch case for menu
                switch(num)
                {
                    case 1:
                        
                        //case 1 takes the user input and assigns it to the variable
                        //set name
                        PersonDatabase[dbcount].setName(personname);
                        cout << "First things first. Lets set up youre profile." << endl;
                        cout << endl;
                        //input age
                        cout << "Please type in your age?" << endl;
                        cin >> personage;
                        // getline(cin, personage);
                        
                        //input height
                        cout << "Please type your height (in inches)." << endl;
                        cin >> personheight;
                        // getline(cin, personheight);
                        //PersonDatabase[dbcount].PersonProfile.setHeight(stoi(personheight));

                        //input gender
                        cout << "Please type your gender." << endl;
                        cin >> persongender;
                        // getline(cin, persongender);
                        //PersonDatabase[dbcount].PersonProfile.setGender(persongender);

                        //input star sign
                        cout << "Please type in your star sign." << endl;
                        cin >> personsign;
                        // getline(cin, personsign);
                        //PersonDatabase[dbcount].PersonProfile.setStarSign(personsign);

                        //input job
                        cout << "Please type in your job." << endl;
                        cin >> personjob;
                        // getline(cin, personjob);
                        //PersonDatabase[dbcount].PersonProfile.setJob(personjob);

                        //takes the variables and sets it to the person profile database array
                        PersonDatabase[dbcount].setPersonProfile(personage, stoi(personheight), persongender, personsign, personjob);

                        //input creative interest
                        cout << "Please enter an interest that is creative." << endl;
                        cin >> personcreativity;

                        //input sports
                        cout << "Please enter an interest of sports." << endl;
                        cin >> personsports;

                        //input food
                        cout << "Please enter your favorite food." << endl;
                        cin >> personfood;

                        //input hobby
                        cout << "Please enter your hobby(one word)." << endl;
                        cin >> personhobby;

                        //input music
                        cout << "Please enter your favorite music genre." << endl;
                        cin >> personmusic;
                        cout << endl;

                        //takes the variables and sets it to the person interests database array
                        PersonDatabase[dbcount].setPersonInterests(personcreativity, personsports, personfood, personhobby, personmusic);
                        dbcount++;

                        break;

                    case 2:
                        //move on map to another person
                        char tempmove;
                        
                        // cout<<"Generating Current Map"<< endl;
                        // if (firsttime==0)
                        // {
                        //     CurrentMap.generateMap(PersonDatabase, dbcount);
                        //     firsttime=1;
                        // }   
                        
                        // CurrentMap.displayMap();
                        // DBlocation = CurrentMap.isOptionLocation();
                        // if(DBlocation>=0)
                        // {
                        //     CompValue = tempCompatibility.calcCompatability(PersonDatabase[dbcount-1].getPersonInterests(), PersonDatabase[DBlocation].getPersonInterests());
                        //     cout << "Your compatability is " << CompValue << endl;
                        // }
                        int quit;
                        cout <<"Below is how you move on Map" << endl;
                        //use the quit variable to keep the map moves on a loop
                        cout << "If you would like to make a move type 1 or to exit the map type 0." << endl;
                        cin >> quit;
                        while(quit == 1)
                        {
                            cout << endl;
                            cout << "Generating Current Map"<< endl;
                            //if the map is being generated for the first time then call the generate map function in map.cpp
                            if (firsttime==0)
                            {
                                CurrentMap.generateMap(PersonDatabase, dbcount);
                                //after the first time the bool is set to 1
                                firsttime=1;
                            }   
                            //calls display map function in map.cpp
                            CurrentMap.displayMap();
                            //sets a value called database location to check is the user is on the same spot on map as one of the options
                            DBlocation = CurrentMap.isOptionLocation();
                            if(DBlocation>=0)
                            {
                                //prints compatability (score) if the psoitions are the same
                                CompValue = tempCompatibility.calcCompatability(PersonDatabase[dbcount-1].getPersonInterests(), PersonDatabase[DBlocation].getPersonInterests());
                                cout << "Your compatability is " << CompValue << endl;
                            }
                            //prompts user to select a move to make
                            cout << "Select a move." << endl;
                            //calls the display moves function
                            CurrentMap.displayMoves();
                            cin >> tempmove;

                            //calls the execute move function
                            //CurrentMap.executeMove(tempmove);
                            //CurrentMap.displayMap();
                            
                            //exit map if an invalid move is entered
                            if(CurrentMap.executeMove(tempmove) == false)
                            {
                                break;
                            }
                        }
                        
                        break;
                    
                    case 3:
                        //open a person's profile after moved on the map
                        //using getters
                        DBlocation = CurrentMap.isOptionLocation();
                        //asks user which profile they want to see on the map using dblocation
                        cout << "Whose profile would you like to view?" << endl;
                        cin >> DBlocation;
                        cout << endl;
                        cout << "Please see detailed profile" << endl;
                        //assigns temp person profile and interests using person database array and getter in the person class 
                        tempPersonProfile = PersonDatabase[DBlocation].getPersonProfile();
                        tempPersonInterest = PersonDatabase[DBlocation].getPersonInterests();
                        
                        //prints information
                        cout << "Name: " << "Hidden the name due to PII data" << endl;
                        cout << "Age: " << tempPersonProfile.getAge() << endl;
                        cout << "Height: " << tempPersonProfile.getHeight() << endl;
                        cout << "Gender: " << tempPersonProfile.getGender() << endl;
                        cout << "Star Sign: " << tempPersonProfile.getStarSign() << endl;
                        cout << "Job: " << tempPersonProfile.getJob() << endl;

                        cout << "Creativity: " << tempPersonInterest.getCreativity() << endl;
                        cout << "Sports: " << tempPersonInterest.getSports() << endl;
                        cout << "Food: " << tempPersonInterest.getFood() << endl;
                        cout << "Hobby: " << tempPersonInterest.getHobby() << endl;
                        cout << "Music: " << tempPersonInterest.getMusic() << endl;
                        cout << endl;
                        
                        break;

                    case 4:
                        //calculates compatability between user and the person whos spot they are on
                        //int compatability = calcCompatability(Interests currentPersonInterest, Interests currentPositionInterest);
                        //cout << "Your compatability with this person is " << compatability << endl;

                        //asks user which person they want to see compatability with
                        cout << "Please input the number for the person on the map you would like to test compatability." <<endl;
                        cin >> temppos;
                        cout << "Showing Compatability for Selected Person" << endl;
                        cout << endl;

                        //calculates and prints compatability
                        CompValue = tempCompatibility.calcCompatability(PersonDatabase[dbcount-1].getPersonInterests(), PersonDatabase[temppos].getPersonInterests());
                        cout << "Your compatability is " << CompValue << endl;


                        break;

                    case 5:
                        //asks of they want to match with that person
                        int compatablilty;
                        bool ret;
                        int option;

                        //ret = tempCompatibility.calcCompatability(PersonDatabase[dbcount].getPersonInterests(), PersonInterest);

                        //set match is a bool function which i am calling
                        ret = Match().setMatch(compatablilty);
                        
                        //if return is true then break and exit out of game
                        if(ret == true)
                        {
                            KeepGoing = 0;
                            break;
                        }
                        //if return is false
                        else
                        {
                            //asks if user wants to continue game (bc match was not found)
                            cout << "Would you like to continue the game?" << endl;
                            cout << "Type 1 for yes or 0 for no." << endl;
                            cin >> option;
                            
                            //if they enter 1 then break
                            if(option == 1)
                            {
                                break;
                            }
                            //else the keep going bool will be 0 and game will end
                            else if(option == 0)
                            {
                                cout << "Goodbye." << endl;
                                KeepGoing = 0;
                                break;
                            }
                            //invalid input will also end game
                            else
                            {
                                cout << "invalid input" << endl;
                                KeepGoing = 0;
                                break;
                            }
                        }
                        
                        // cout << "Compatability can only be tested when you navigate to an option." << endl;
                        
                        break;
                
                    case 6:
                        //exit option
                        cout << "Thank you! We will see you soon" << endl;
                        KeepGoing=0;
                        break;

                    default:
                        //invalid input default case
                        cout << "Invalid input." << endl;
                        KeepGoing=0;
                        break;
                }
        }
    }
    else
    {
        //if user does not want to play the game
        cout << "Now you'll be alone forever. Goodbye." << endl;
    }

    return 0;
}

/*
this function was going to used to search if a persons profile already exists after setting and storing it, but it is not used in the game anymore
I left it in however in case I want to use it again in future
parameters: string name, person database array of objects
*/

int SearchDB(string tempname, Person DBPersonDatabase[])
{
    int searchcount=0;

    while(searchcount<MAXDB)
    {
        if(tempname==DBPersonDatabase[searchcount].getName())
            {
                return searchcount;
            }
        //cout << "Name:" << DBPersonDatabase[searchcount].getName();
        searchcount++;
    }
    return -1;
}
