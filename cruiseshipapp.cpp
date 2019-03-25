/**
  CS-11 FinalProject
  cruiseshipapp.cpp
  Purpose:

  @author Bruce Hartman
  @version 1.1 12/2/16
 */
#include "passenger.h"
#include "activity.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/**
  Loads complete cruise event data from file into vector

  @param events vector containing events on a cruise
  @param filename input file with calendar of events
*/
void readCruiseData(vector<Activity>& events, string filename);

/**
   from a ifstream, build the vector of activities

   @param fin file with data to be read into vector

   @return vector containing events in the file
 */
vector<Activity> buildEventVector(ifstream& fin);
/**
   print header for activities list
 */
void printHeader();
/**
  Prints complete cruise data contained in event parameter

  @param events vector containing events on a cruise
*/
void printCalendarData(vector<Activity>& events);

/**
  Prints complete cruise data contained in event parameter to Output file

  @param events vector containing events on a cruise
*/
void printCalendarData(vector<Activity>& events, ofstream& fout);

/**
  Prints complete list of tags associated with calendar of events

  @param events vector containing events on a cruise
*/
void printTags(const vector<Activity>& events);

/**
    removes duplicate entries from a vector

    @param tagsList vector of strings to remove dups from
 */
void removeDups(vector<string>& tagList);

/**
    sort entries in a vector alphabetically

    @param tagsList vector of strings to sort
 */
void sortTags(vector<string>& tagList);

/**
    sort entries in event vector by day and time

    @param evList vector of events to sort
 */
void sortEvents(vector<Activity>& evList);

/**
   build passenger profile from scratch (first time in program)
 */
void buildFirst(Passenger& profile);

/**
   prompt for and print out all events of a specified interest

   @param events calendar of all events on the ship
 */
void getIntList(vector<Activity>& events);

/**
   prompt for and print out all events of on a specified day

   @param events calendar of all events on the ship
 */
void getDayList(vector<Activity>& events);

/**
   given a calendar of events, returns the length of the cruise

   @param events a vector of activity objects
   @return integer with the number of days the activities span
 */
int findNumDays(vector<Activity>& events);

/**
   list all events in the given day

   @param events a vector of activity objects
   @param day day of cruise to list events
 */
void listEvents(vector<Activity>& events, int day);

/**
   list all events with a specified tag

   @param events a vector of activity objects
   @param tag representing the type of events to filter on
 */
void listEvents(vector<Activity>& events, string tag);

/**
   prints out all activities a passenger has signed up for

 */
void showSignups(Passenger& psngrProf);

/**
   adds an event ot a passenger's signup sheet

   @param psngrProf the profile of the passenger to add event to
   @param events list of ship events
 */
void addSignup(Passenger& psngrProf, vector<Activity> events);

/**
   removes an event from a passenger's profile

   @param psngrProf the profile of the passenger to remove event from
 */
void removeSignup(Passenger& psngrProf);

/**
  saves user profile to output file

  @param passProf Passenger Profile
  @param fileName The name of the file to which to write.
*/
void saveProfile(Passenger passProf, string fileName);


int main() {
    vector<Activity> events;  // calendar of cruise ship events
    string eventSched = "eventsSched.txt";
    readCruiseData(events, eventSched); // read in cruise data
    sortEvents(events);

    // menu options
    const int SHOW_PROGRAMMING = 1;
    const int LIST_RELEVANT = 2;
    const int LIST_DAY = 3;
    const int SHOW_SIGNUPS = 4;
    const int ADD_EVENT = 5;
    const int REMOVE_EVENT = 6;
    const int EXIT = 0;

    Passenger psngrProf;
    cout << "Welcome to the cruise scheduler.\n";
    ifstream fin("passengerProfile.txt");
    if (fin.fail()) {
        cout << "No profile found.  Please build a profile to proceed.\n";
        buildFirst(psngrProf);
    } else {
        string name;
        double fees;
        fin >> ws;
        getline(fin, name);
        fin >> fees;
        vector<Activity> signups;
        signups = buildEventVector(fin);

        // call overloaded constructor
        Passenger newPass(name, fees, signups);
        psngrProf = newPass;

        fin.close();
    }
    cout << "Hello " << psngrProf.getName() << ", let's get started.\n";
    int choice = 0;
    do {
        cout << "\nWhat would you like to do?\n\n";
        cout << "1: Show all ship events\n"
             << "2: list programs with based on interest\n"
             << "3: list programs on a specific day\n"
             << "4: show your sign-ups (with total cost)\n"
             << "5: add event to your schedule\n"
             << "6: remove event from your schedule\n"
             << "0: Exit (and save your choices)\n"
             << "enter choice: ";
        cin >> choice;
        switch (choice) {
        case SHOW_PROGRAMMING:
            printCalendarData(events);
            break;
        case LIST_RELEVANT:
            getIntList(events);
            break;
        case LIST_DAY:
            getDayList(events);
            break;
        case SHOW_SIGNUPS:
            showSignups(psngrProf);
            break;
        case ADD_EVENT:
            addSignup(psngrProf, events);
            break;
        case REMOVE_EVENT:
            removeSignup(psngrProf);
            break;
        }
    } while(choice != EXIT);

    saveProfile(psngrProf, "passengerProfile.txt");
    return 0;
}

void readCruiseData(vector<Activity>& events, string filename) {
    ifstream fin(filename.c_str());
    if (fin.fail()) {  // cruise data must exist or exit
        cout << "Input file failed to open.\n";
        exit(-1);
    }
    events = buildEventVector(fin);
    fin.close();
}

vector<Activity> buildEventVector(ifstream& fin) {
    vector<Activity> tEvents;
    while(fin.good()) {
        Activity temp;
        temp.read(fin);
        if (fin.good()) {
            tEvents.push_back(temp);
        }
    }
    return(tEvents);
}


void printHeader() {
    cout << setw(EVENT_WIDTH) << left << "Event Name"
         << setw(DAY_WIDTH) << left << "Day"
         << setw(TIME_WIDTH) << left << "Time"
         << setw(COST_WIDTH) << left << "Fee"
         << setw(TAGS_WIDTH) << left << " Tags" << endl;
}

void printCalendarData(vector<Activity>& events) {
    cout << setw(EVENT_NUM_WIDTH) << left << "Event# ";
    printHeader();
    for (unsigned i = 0; i < events.size(); i++) {
        cout << setw(EVENT_NUM_WIDTH) << left << i + 1;
        events[i].print();
    }
}


void printCalendarData(vector<Activity>& events, ofstream& fout) {
    for (unsigned i = 0; i < events.size(); i++)
        events[i].print(fout);
}

// prints a sorted list of all tags associated with events on ship
// duplicates removed
void printTags(const vector<Activity>& events) {
    vector<string> tagsList;
    string allTags = "";

    // build a long string of tags, space separated
    for (unsigned i = 0; i < events.size(); i++)
        allTags = allTags + events[i].getTag();

    // parse the aggregated list of all tags and save each tag
    // as separate element in tag vector
    string tstr;
    int start = 0, end = 0;
    while (start != (int) allTags.length()) {

        // ref: cplusplus.com string::find_first_of
        end = allTags.find_first_of(" ", start+1);
        if (end > 0) {  // found a space
            tstr = allTags.substr(start, end - start);
            start = end + 1;
        } else {
            tstr = allTags.substr(start);
            start = allTags.length();
        }
        tagsList.push_back(tstr);
    }
    removeDups(tagsList);
    sortTags(tagsList);

    // print sorted list of tags
    for (unsigned i = 0; i < tagsList.size(); i++) {
        cout << tagsList[i];
        if (i < tagsList.size() - 1 )
            cout << ", ";
    }
    cout << endl;
}

void removeDups(vector<string>& tagsList) {
    string tempTag;
    for (unsigned i = 0; i < tagsList.size(); i++) {
        tempTag = tagsList[i];
        for (unsigned j = i+1; j < tagsList.size(); j++)
            if (tempTag == tagsList[j]) {  // remove dup element from vector
                for (unsigned k = j; k < tagsList.size() - 1; k++) {
                    tagsList[k] = tagsList[k + 1];
                }
                tagsList.pop_back();
                j--;
            }
    }
}

// Sort a vector. Source: my brain
void sortTags(vector<string>& tagsList) {
    string tempTag;
    bool sorted;
    do {
        sorted = true;
        for (unsigned i = 0; i < tagsList.size() - 1; i++)
            if (tagsList[i] > tagsList[i+1]) {
                tempTag = tagsList[i];
                tagsList[i] = tagsList[i+1];
                tagsList[i+1] = tempTag;
                sorted = false;
            }
    } while (!sorted);
}

void sortEvents(vector<Activity>& evList) {
    Activity tEvent;
    bool sorted;
    do {
        sorted = true;
        for (unsigned i = 0; i < evList.size() - 1; i++)
            if(evList[i].getDay() > evList[i+1].getDay()) {
                tEvent = evList[i];
                evList[i] = evList[i+1];
                evList[i+1] = tEvent;
                sorted = false;
            } else if (evList[i].getDay() == evList[i+1].getDay()) {
                if (evList[i].getHour() > evList[i+1].getHour()) {
                    tEvent = evList[i];
                    evList[i] = evList[i+1];
                    evList[i+1] = tEvent;
                    sorted = false;
                } else if (evList[i].getHour() == evList[i+1].getHour()) {
                    if (evList[i].getMinutes() > evList[i+1].getMinutes()) {
                        tEvent = evList[i];
                        evList[i] = evList[i+1];
                        evList[i+1] = tEvent;
                        sorted = false;
                    }
                }
            }
    } while (!sorted);
}

void buildFirst(Passenger& passProf) {
    cout << "\nWhat is your name? ";
    string name;
    cin >> ws;
    getline(cin, name);
    passProf.setName(name);
}

void getIntList(vector<Activity>& events) {
    cout << "\nHere are the tags associated with programs on the ship\n";
    printTags(events);
    cout << "\nWhich interest would you like to search on? ";
    string intChoice;
    cin >> intChoice;
    listEvents(events, intChoice);
}

void listEvents(vector<Activity>& events, string tag) {
    bool found = false;
    printHeader();
    for(unsigned i = 0; i < events.size(); i++) {
        // ref:http://www.cplusplus.com/reference/string/string/find/
        if(events[i].getTag().find(tag) != std::string::npos) {
            events[i].print();
            found = true;
        }
    }
    if(found == false)
        cout << "NO EVENTS MATCHING SEARCH CRITERIA FOUND: tag = \""
             << tag << "\"\n\n";
}

void getDayList(vector<Activity>& events) {
    cout << "\nThere are " << findNumDays(events) << " days on the ship. \n";
    cout << "Which day's events do you want to see? ";
    int day;
    cin >> day;
    listEvents(events, day);
}

// list events on a given day
void listEvents(vector<Activity>& events, int day) {
    bool found = false;
    printHeader();
    for(unsigned i = 0; i < events.size(); i++) {
        if(day == events[i].getDay()) {
            events[i].print();
            found = true;
        }
    }
    if(found == false)
        cout << "NO EVENTS MATCHING SEARCH CRITERIA FOUND day = \""
             << day << "\"\n\n";
}

int findNumDays(vector<Activity>& events) {
    int numDays = 0;
    for (unsigned i = 0; i < events.size(); i++)
        if(numDays < events[i].getDay())
            numDays = events[i].getDay();
    return numDays;
}

void addSignup(Passenger& psngrProf, vector<Activity> events) {
    printCalendarData(events);
    cout << "Which event would you like to add to your schedule? ";
    int eventNum;
    cin >> eventNum;
    eventNum--;   // adjust index to start at 0
    Activity tEvent = events[eventNum];
    psngrProf.addEvent(tEvent);

    // incease fees owed by amount of event being added
    psngrProf.setFees(psngrProf.getFees() + tEvent.getCost());
    vector<Activity> eSignups;
    eSignups = psngrProf.getCalendar();
    sortEvents(eSignups);
    psngrProf.setCalendar(eSignups);
}

void removeSignup(Passenger& psngrProf) {
    vector<Activity> tCalendar;
    tCalendar = psngrProf.getCalendar();
    printCalendarData(tCalendar);
    cout << "Which event would you like to remove from your schedule? ";
    int eventNum;
    cin >> eventNum;

    if (eventNum < 1 || eventNum > (int) tCalendar.size())
        cout << "ILLEGAL REQUEST TO REMOVE EVENT #" << eventNum
             << " (EVENT DOES NOT EXIST)\n\n";
    else {
        eventNum--;   // adjust index to start at 0

        // reduce fees owed by amount of event being removed
        psngrProf.setFees(psngrProf.getFees() - tCalendar[eventNum].getCost());

        psngrProf.removeEvent(eventNum);
    }
}

void showSignups(Passenger& psngrProf) {
    vector<Activity> tCalendar;
    tCalendar = psngrProf.getCalendar();
    printCalendarData(tCalendar);
    cout << "Your total fees will be: $" << fixed << setprecision(2)
         << psngrProf.getFees() << endl;
}


void saveProfile(Passenger passProf, string fileName) {
    ofstream fout(fileName.c_str());
    if (fout.fail()) {
        cout << "Unable to save customer profile!\n";
        return;
    }
    fout << passProf.getName() << endl;
    fout << passProf.getFees() << endl;
    vector<Activity> tCalendar;
    tCalendar = passProf.getCalendar();
    printCalendarData(tCalendar, fout);

    fout.close();
}
