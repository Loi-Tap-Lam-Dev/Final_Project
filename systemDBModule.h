// TEMPORARY ABANDONED
// Not sure if this file is useful or not lul

#pragma once

#include "userDBModule.h"

using namespace std;

class Class {
    public:
        string className;

        Student *p_classStudentList;
        Class *p_nextClass;
};

class Subject {
    public:
        string startDate, endDate;
        int maxStudents = 50;

        Class *p_subjectClassList;

        Student *p_subjectStudentList;
};

class Semester {
    public:
        Student p_semesterStudentList;
        Subject p_semesterSubjectList;

        Semester *p_nextSemester;
};

class Year {
    public:
        string yearName;

        Class *p_yearClassList;
        Semester *p_yearSemesterList;

        Year *p_nextYear;
};