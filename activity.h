/**
    CS-11 Final Project
    activity.h
    class header of activity class

    @author Bruce Hartman
    @version 1.1 11/20/16
*/
#ifndef ACTIVITY_H_
#define ACTIVITY_H_
#include <sstream>
#include <vector>
using namespace std;

// Formatting constants
const int EVENT_WIDTH = 22;
const int COST_WIDTH = 8;
const int DAY_WIDTH = 5;
const int TIME_WIDTH = 7;
const int TAGS_WIDTH = 30;
const int EVENT_NUM_WIDTH = 7;

// Activity class prototypes
class Activity {
public:
    /**
       default constructor
     */
    Activity();

    /**
       read one activity from text file and populate calling object

       @param fin open filestream pointing to the txt file with activities
     */
    void read(ifstream& fin);

    /**
       print activity information of calling object to standard output
     */
    void print() const;

    /**
       print activity information of calling object to an output file
       (output file used to initialize next app instantiation with
       passenger activity data)

       @param fout output file to write data to
     */
    void print(ofstream& fout) const;

    /**
       getter for tags associated with activity

       @return string containing the full list of tags for an activity,
        space separated
     */
    string getTag() const;

    /**
       getter for day associated with activity

       @return integer representing the day of the activity
     */
    int getDay() const;

    /**
       getter for hour of an activity

       @return int representing the hour (time) of the activity
     */
    int getHour() const;

    /**
       getter for minutes of an activity

       @return int representing the minutes (time) of the activity
     */
    int getMinutes() const;

    /**
       getter for cost of an activity

       @return double representing the cost of the activity
     */
    double getCost() const;
private:
    string name;  // name of activity
    int day;  // day of cruise when activity takes place
    int hour;   // time of activity (hours)
    int minutes; // time of activity (minutes)
    double cost;  // cost of program
    vector<string> tag; // type of activity

};

#endif /* ACTIVITY_H_ */
