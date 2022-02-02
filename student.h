#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Student{
    private:
        int rollNo;
        string name;
        int age;
        string email;
        string contactNumber;

        int generateRollNo();
    public:
        Student();
        void setData();
};

#endif