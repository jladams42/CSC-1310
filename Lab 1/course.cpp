#include "course.h"
#include <iostream>

using namespace std;

// createCourse function definition. Also this holds the initialization for the new string array of numSections and returns the entire object via newCourse.
Course* createCourse(string name, string location, int numSections, int creditHours){
    Course* newCourse = new Course(name, location, new string[numSections], numSections, creditHours );

    return newCourse;
};

// printCourse function definition that uses members of the Course struct where we have our pointers. 
void printCourse(Course* course){
    cout << "\nCOURSE NAME:\t\t" << course->name << endl;
    cout << "\nCOURSE LOCATION:\t" << course->location << endl;
    cout << "\nCOURSE HOURS:\t\t" << course->creditHours << endl;
    cout << "\nNUMBER OF SECTIONS?\t" << course->numSections << endl;
    cout << "\nCOURSE SECTIONS:\t\t";
    for (int i = 0; i < course->numSections; i++){
        cout << "\n\t\t\t\t" << course->sections[i] << endl;
    }
};

// This destroys the course to free up the memory and prevent leaks.
void destroyCourse(Course* course){
    delete course;
};