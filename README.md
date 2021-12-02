# dating-game
Programmed a dating game for my computing class at CU Boulder. 
----------------------------
HOW TO COMPILE AND RUN
----------------------------
compile: g++ -std=c++11 gameDriver.cpp person.cpp interests.cpp profile.cpp map.cpp match.cpp compatability.cpp
run: ./a.out

----------------------------
DEPENDENCIES
----------------------------
All the .h files must be in the same directory as cpp files 
these include:
compatability.h
person.h 
profile.h
interests.h
match.h

---------------------------
SUBMISSION INFORMATION
---------------------------
CSCI 1300 Fall 2021 Project 3
Author: Birwa Balar
Recitation: 117 - Naga Sai Meenakshi Sistla
Date: November 1, 2021

---------------------------
ABOUT THIS PROJECT
---------------------------
This project is a dating game in which the user inputs some basic information about
themselves. Their interests will calculate compatability and with that they can move on
the map to other potential love matches to see their compatability with that option
on the map (the numbers). They can also open that person's profile to learn more about them 
as well as select to match with them. If compatability is higher than 70% then its a match.
