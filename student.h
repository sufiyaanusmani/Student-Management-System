#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Student{
    private:
        int rollNo;
        char name[20];
        int age;
        char email[20];
        char contactNumber[20];

        int generateRollNo();
        void storeData();
    public:
        void setData();
        void showData();
        void showAllStudents();
        // void searchStudent();
        // void deleteStudent();
        // void modifyStudent();
};

int Student::generateRollNo(){
    ifstream fin;
    int id;
    bool isFound = false;
    srand(time(0));
    fin.open("student.dat", ios::in|ios::binary);
    if(!fin){
        cout << "File does not exists" << endl;
    }else{
        while(1){
            id = (rand() % 10000) + 100000;
            fin.read((char*)this, sizeof(*this));
            while(fin.eof() == 0){
                if(this->rollNo == id){
                    isFound = true;
                    break;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if(isFound == false){
                break;
            }
        }
    }
    fin.close();
    return id;
}

void Student::setData(){
    this->rollNo = generateRollNo();
    system("cls");
    cout << "Enter name: ";
    fflush(stdin);
    gets(name);
    cout << "Enter age: ";
    fflush(stdin);
    cin >> this->age;
    cout << "Enter email: ";
    fflush(stdin);
    gets(email);
    cout << "Enter contact number: ";
    fflush(stdin);
    gets(contactNumber);
    
    storeData();
}

void Student::showData(){
    system("cls");
    cout << "ID: " << this->rollNo << endl;
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
    cout << "Email: " << this->email << endl;
    cout << "Contact Number: " << this->contactNumber << endl << endl;
    cout << "Press any key to continue...";
    getch();
}

void Student::storeData(){
    ofstream fout;
    fout.open("student.dat", ios::app|ios::binary);
    fout.write((char*)this, sizeof(*this));
    fout.close();
}

void Student::showAllStudents(){
    ifstream fin;
    fin.open("student.dat", ios::in|ios::binary);
    if(!fin){
        cout << "File does not exists" << endl;
    }else{
        fin.read((char*)this, sizeof(*this));
        while(fin.eof() == 0){
            cout << "ID: " << this->rollNo << endl;
            cout << "Name: " << this->name << endl;
            cout << "Age: " << this->age << endl;
            cout << "Email: " << this->email << endl;
            cout << "Contact Number: " << this->contactNumber << endl << endl;
            fin.read((char*)this, sizeof(*this));
        }
    }
    fin.close();
    getch();
}

#endif