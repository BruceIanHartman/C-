/**
    CS-11 Final Project
    passenger.h
    class header of passenger class

    @author Bruce Hartman
    @version 1.1 11/20/16
*/

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "Activity.h"
#include <sstream>
#include <vector>
using namespace std;

//  Passenger class prototypes
class Passenger {
public:
    /**
       default constructor
     */
    Passenger();

    /**
       constructor to build an object with three parameters

       @param pName passenger's name
       @param pFee current cost of passenger's signups
       @param signUps vector of signup activities
     */
    Passenger(string pName, double pFee, vector<Activity> signups);

    /**
       member function to add event to passenger's calendar

       @param newEvent Activity to add to passenger's signups
     */
    void addEvent(Activity newEvent);

    /**
       remove event from passenger's calendar

       @param eventNumber index of Activity to remove from passenger's signups
     */
    void removeEvent(int eventNumber);

    /**
       update the total fees for events in passentger's calednar

       @param newFee updated fees to be billed to the passenger
            for planned calendar
     */
    void setFees (double newFee);

    /**
       set name of passenger

       @param newName sting containing passenger's name
     */
    void setName (string newName);
    /**
       set Calendar of signups associated with the passenger

       @param newCalendar calendar of signups
     */
    void setCalendar(vector<Activity> newCalendar);

    /**
       get name of passenger

       @return name of passenger
     */
    string getName() const;

    /**
       get total fees for all activities passenger signed up for

       @return double containing total fees
     */
    double getFees() const;

    /**
       get calendar of events passenger has signed up for

       @return vector of activity objects
     */
    vector<Activity> getCalendar() const;
private:
    string name;  // name of passenger
    double fees;  // cost of all activities
    vector<Activity> calendar;  // list of activities signed up for
};

#endif /* PASSENGER_H_ */
