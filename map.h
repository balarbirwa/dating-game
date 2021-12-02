//CSCI Fall 2021
//Birwa Balar
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Map Class
#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include "person.h"

using namespace std; 

class Map
{
     private:
          static const int num_rows = 5;
          static const int num_cols = 9;
          static const int num_option = 44;

          int playerPosition[2];
          //int bestBuyPosition[2];
          int optionPositions[num_option][2];
          string mapData[num_rows][num_cols];
          int option_count;

     public :
          Map();

          void resetMap();

          // getters
          int getPlayerRowPosition();
          int getPlayerColPosition();
          int getOptionCount();

          // setters
          void setPlayerRowPosition(int);
          void setPlayerColPosition(int);
          void setOptionCount(int);

          bool spawnOption(int, int);

          void displayMap();
          void displayMoves();  
          bool executeMove(char);

          int isOptionLocation();

          bool generateMap(Person [], int);

};
 
#endif
