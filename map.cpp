//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Map Class
#include "map.h"
#include "person.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std; 

/*
I took the given map class and edited it to fit my CYO map.
My map will have the player/person using the dating game and three random spots on the map
will be a potential option person whose profile can be viewed if the player chooses. The player
will move on the map and when on a spot it will display the option person's profile.
The player can then choose to test compatability, match or move to another spot.
*/

Map::Map()
{
    resetMap();
}

// resets player position, count values, and initializes values in position arrays to -1
void Map::resetMap() {
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    option_count = 0;

    for (int i = 0; i < num_option; i++) 
    {
       optionPositions[i][0] = -1;
       optionPositions[i][1] = -1;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = "--";
        }
    }
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getOptionCount() {
    return option_count;
}

// set player's row position to parameter row
void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}

// set player's column position to parameter row
void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

void Map::setOptionCount(int count) {
    option_count = count;
}

/* remove Option from map
 * Parameters: where to remove NPC -- row (int), col (int)
 * Return: (bool) false if no more space in optionPositions array
 *                      or if (row, col) is an invalid position
 *                      or if (row, col) is already populated; else true
 */
bool Map::spawnOption(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    if (option_count >= num_option) {
       return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != "--") {
        return false;
    }

    if (optionPositions[option_count][0] == -1 && optionPositions[option_count][1] == -1) {
       optionPositions[option_count][0] = row;
       optionPositions[option_count][1] = col;
       mapData[row][col] = "xx";
       option_count--;
       return true;
    }

    return false;
}



//return true if x, y position has an option there
int Map::isOptionLocation()
{
   for(int i = 0; i < num_option; i++)
   {
       //cout<<"Option:"<< optionPositions[i][0]<< " "<< optionPositions[i][1] <<endl;
       //cout<<"Player:"<< playerPosition[0]<< " " << playerPosition[1] <<endl;
       if(optionPositions[i][0] == playerPosition[0] && optionPositions[i][1] == playerPosition[1])
       {
           return i; 
       }
   }
   return -1; 
}


void Map::displayMoves(){
    if(!(playerPosition[0] == 0)){
        cout << "w (Up)" << endl;
    }
    if(!(playerPosition[0] == (num_rows - 1))){
        cout << "s (Down)" << endl; 
    }
    if(!(playerPosition[1] == 0)){
        cout << "a (Left)" << endl; 
    }
    if(!(playerPosition[1] == (num_cols - 1))){
        cout << "d (Right)" << endl; 
    }
}

/*
 * This function takes in user input
 * and updates playerPosition on the map.
 * Parameters: move (char) -- 'w' (up), 'a' (left), 's' (down), 'd' (right)
 * Return: (bool) if move is valid, then true, else false
 */
bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        //cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * This function prints a 2D map in the terminal.
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) 
            {
                cout << "xx ";
            }
            // } else if (mapData[i][j] == 'O') {  // don't show hacker on the map
            //     cout << 'O';
            // }
            else 
            {
                cout << mapData[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool Map::generateMap(Person PersonDB[], int DBsize)
{
    int DBi=0;

    resetMap();
    while(DBi < DBsize)
    {
        int irandrow =0, irandcol = 0;

        irandrow = rand() % 5;
        irandcol = rand() % 9;
        optionPositions[DBi][0]=irandrow;
        optionPositions[DBi][1]=irandcol;
        if(mapData[irandrow][irandcol] =="--")
        {   
            //int a = DBi;
            //char *intStr = itoa(a);
            
            string str = to_string(DBi);
            // inserting adding empty char in front of the integer to align the mapData
            if (DBi < 10)
            {
                str.insert(0," ");
            }
            mapData[irandrow][irandcol] = str;
            DBi++;
        }
    }
    return 1;
}
