Name: Bruce Hartman
Email: BruceIan20@gmail.com
Programming Partner: none
OS: Mac OS X (El Capitan)
Asn#: Final Project
Status: Completed
Files:
- Makefile - to build the cruiseshipapp
- cruiseshipapp.cpp - main program
- passenger.h - signatures for passenger class
- passenger.cpp - passenger class implementation
- activity.h - signature for activity class
- activity.cpp - activity class implementation
- eventsSched.txt - cruis ship data (input to cruiseshipapp

- face.cpp: Exercise 13.1: graphics exercise
- funreview.cpp: Exercise 14.2: function review
- funrec.cpp: Exercise 14.3: recursion
- README.txt: Meta information about the homework files.


Hours on Lab Exercises: 0
Hours Working With Partner: 0.0
Hours Work::q!
:q!
ing Alone: 0
Hours Total: 0

Extra Credit:
- presented to class one day early
- Coded vector of objects and processed in loop: cruiseshipapp.cpp: line 262-264
- coded sort functions
--- Sort words in string: cruiseshipapp: sortTags():ln 329 
    algorithm source: my brain
--- Sort a vector of objsect: sortEvents():ln 344 
    algorithm source: my brain
- XC features : 
--- cruiseshipapp.cpp:290: use of find_first_of to parse space seperated string
        ref: http://www.cplusplus.com/reference/string/string/find_first_of/
--- cruiseshipapp.cpp:394: use of string find
        ref:http://www.cplusplus.com/reference/string/str ing/find/


Program Purpose:
CruiseShip calendaring app:
This program helps a passenger find activities on a cruise ship that may be
of interest and lets the passenger sign up for and create a personalized 
calendar of events.  
GENERAL OPERATION:
+) read in cruise ship's full set of events from text file
+) check for file containing passenger signups:
--- if present, read it in
--- if not, build for first time
+) provide menu to view all events and modify sign-ups
+) upon exit, save passengers signups to a file for initialization on 
next app instantiation

How to Use:
1. Install the source code into a directory and compile by typing: make
2. To run at the command line, type: cruiseshipapp

Specifications Met:
##  Specification             File             Line#   Comment
--  -------------             ----             -----   -------
1.  No global variables
2.  Classes & objects         activity.h        24
                              passnger.h        18
3.  a. while loop             cruiseshipapp.cpp 288
    b. for loop               cruiseshipapp.cpp 281
    c. if statement           cruiseshipapp.cpp 350
4.  a. void function          cruiseshipapp.cpp 313
    b. non-void function      cruiseshipapp.cpp 428
    c. pass-by-value function cruiseshipapp.cpp 483
    d. pass by reference func cruiseshipapp.cpp 269
5.  overloaded function       cruiseshipapp.cpp 390, 414
6.  overloaded constructor    passenger.cpp     18, 23
7.  vector type               cruiseshipapp.cpp 154
8.  a. Read from file         activity.cpp      29    filename: eventsSched.txt
    b. Write to file          activity.cpp      77    filename: 
                                                            passengerProfile.txt
    c. Use of fail            cruiseshipapp.cpp 171, 230, 485
    d. Stream parameter       activity.cpp      76    function:Activity::print()
9.  setw()                    activity.cpp      64
10. setprecision()            activity.cpp      65
11. Project report            README.txt
12. Code compiles
13. Functions correctly
14. Meets documentation requirements

