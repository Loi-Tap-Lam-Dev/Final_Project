// This is a test module, it's
// NOT FULLY developed and checked!

/* ----- USER DATABASE ----- */
#pragma once

#include <string>

using namespace std;

// Base class
class User {
    public:
        int userID, socialID;
        string username, gender, dateOfBirth;

        User *p_nextEntry;

    protected:
        int password;

        // Find a way to encrypt a string password to an integer
        void assignPassword(string pin) {
            // TO DO: Write the function
        }
};

// Two simple user models
// Could and will add more operations for each model later
class Student: public User {
    public:
        int courseEnrolled[5] = {0, 0, 0, 0, 0},
            midtermMark, finalMark, otherMark, GPA, averageMark;

    private:
        bool adminAuthority = false;
};

class SchoolOfficial: public User {
    private:
        bool adminAuthority = true;
};