#pragma once

#include "userDBModule.h"

using namespace std;

class Class {
    public:
        string className;

        Student *p_studentsOfClassListHead;
        Course *p_nextClass;
};

class Subject {
    public:
        string startDate, endDate;
        int maxStudents = 50;

        Student *p_studentOfSubjectListHead;
};