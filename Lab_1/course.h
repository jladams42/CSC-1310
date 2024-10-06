#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

// Struct definition for the Courses the user will enter.
struct Course {
    string name;
    string location;
    string* sections;
    int numSections;
    int creditHours;

    // Constructor for the Course struct and a member list initialization. 
    Course(string name, string location, string* sections, int numSections, int creditHours)
        : name(name), location(location), sections(sections), numSections(numSections), creditHours(creditHours) {};
};

// Function prototypes. 
Course* createCourse(string, string, int, int);
void printCourse(Course* myCourse);
void destroyCourse(Course* myCourse);

#endif