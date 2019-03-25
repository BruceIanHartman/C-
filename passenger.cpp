/*
 * passenger.cpp
 * implemented functions for the passenger class
 *
 *  Created on: Nov 23, 2016
 *      Author: BruceHartman
 */

#include "passenger.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

Passenger::Passenger() {
    name = "noName";
    fees = 0;
}

Passenger::Passenger(string pName, double pFees, vector<Activity> signups) {
    name = pName;
    fees = pFees;
    calendar = signups;
}

void Passenger::setFees (double newFee) {
    fees = newFee;
}
void Passenger::setName (string newName) {
    name = newName;
}
void Passenger::setCalendar(vector<Activity> newCalendar) {
    calendar = newCalendar;
}
string Passenger::getName() const {
    return name;
}
double Passenger::getFees() const {
    return fees;
}
vector<Activity> Passenger::getCalendar() const {
    return calendar;
}
void Passenger::addEvent(Activity newEvent) {
    calendar.push_back(newEvent);
}
void Passenger::removeEvent(int eventNum) {
    for(unsigned i = eventNum; i < calendar.size() - 1; i++)
        calendar[i] = calendar[i + 1];

    calendar.pop_back();
}
