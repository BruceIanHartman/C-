/**
    CS-11 Final Project
    activity.cpp
    activity class - Object containing characteristics of a single activity

    @author Bruce Hartman
    @version 1.1 11/20/16
*/
#include "activity.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

Activity::Activity() {
    name = "unPlanned";
    day = 0;
    hour = 0;
    minutes = 0;
    cost = 0;
}

void Activity::read(ifstream& fin) {
    fin >> ws;
    getline(fin, name);
    fin >> day;
    fin >> hour;
    fin >> minutes;
    fin >> cost;
    string tags;  // line of space separated tags
    fin >> ws;
    getline(fin, tags);

    // parse the input line of tags
    // save each tag as separate element in tag vector
    string tstr;
    int start = 0, end = 0;
    while (start != (int) tags.length()) {
        // ref: cplusplus.com string::find_first_of
        end = tags.find_first_of(" ", start+1);
        if (end > 0) {  // found a space
            tstr = tags.substr(start, end - start);
            start = end + 1;
        } else {
            tstr = tags.substr(start);
            start = tags.length();
        }
        tag.push_back(tstr);
    }
}

void Activity::print() const {
    ostringstream time;
    if (minutes == 0)
        time << hour << ":00";
    else
        time << setprecision(2) << fixed << hour << ":" << minutes;
    cout << setw(EVENT_WIDTH) << left << name
         << setw(DAY_WIDTH) << left << day
         << setw(TIME_WIDTH) << left << time.str()
         << "$" <<  setprecision(2) << fixed
         << setw(COST_WIDTH) << left << cost;

    for (unsigned i = 0; i < tag.size(); i++) {
        cout << tag[i];
        if (i != tag.size() - 1)
            cout << ", ";
        else
            cout << endl;
    }
}
void Activity::print(ofstream& fout) const {
    fout << name << endl;
    fout << day << endl;
    fout << hour << endl;
    fout << minutes << endl;
    fout << setprecision(2) << fixed << cost << endl;

    ostringstream tags;
    for (unsigned i = 0; i < tag.size(); i++) {
        fout << tag[i];
        if (i != tag.size() - 1)
            fout << " ";
    }
    fout << endl;
}
string Activity::getTag() const {
    ostringstream tags;
    for (unsigned i = 0; i < tag.size(); i++) {
        tags << tag[i] << " ";
    }
    return tags.str();
}
int Activity::getDay() const {
    return day;
}
int Activity::getHour() const {
    return hour;
}
int Activity::getMinutes() const {
    return minutes;
}
double Activity::getCost() const {
    return cost;
}
