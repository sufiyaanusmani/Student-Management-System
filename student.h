#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <stdio.h>
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
        void searchStudent();
        void deleteStudent();
        void modifyStudent();
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
    system("cls");
    ifstream fin;
    fin.open("student.dat", ios::in|ios::binary);
    if(!fin){
        cout << "File does not exists" << endl;
    }else{
        printf("Roll No  Name                  Age  Contact Number  Email\n\n");
        fin.read((char*)this, sizeof(*this));
        while(fin.eof() == 0){
            printf("%-6d   %-20s  %-3d  %-14s  %s\n", this->rollNo, this->name, this->age, this->contactNumber, this->email);
            fin.read((char*)this, sizeof(*this));
        }
    }
    fin.close();
    getch();
}

void Student::searchStudent(){
    system("cls");
    int id;
    bool found = false;
    cout << "Enter student roll no to search: ";
    cin >> id;
    ifstream fin;
    fin.open("student.dat", ios::in|ios::binary);
    if(!fin){
        cout << "Error, file does not exists" << endl;
    }else{
        fin.read((char*)this, sizeof(*this));
        while(fin.eof() == 0){
            if(this->rollNo == id){
                found = true;
                showData();
                break;
            }
            fin.read((char*)this, sizeof(*this));
        }
    }
    if(found == false){
        cout << "This student does not exists" << endl;
        Sleep(3000);
    }

    fin.close();
}

void Student::deleteStudent(){
    int id;
    bool found = false;
    cout << "Enter Roll No: ";
    cin >> id;
    ifstream fin;
    ofstream fout;
    fout.open("temp.dat", ios::out|ios::binary);
    fin.open("student.dat", ios::in|ios::binary);
    if(!fin){
        cout << "File not found" << endl;
    }else{
        fin.read((char*)this, sizeof(*this));
        while(fin.eof() == 0){
            if(this->rollNo != id){
                fout.write((char*)this, sizeof(*this));
            }else if(this->rollNo == id){
                found = true;
            }
            fin.read((char*)this, sizeof(*this));
        }
    }
    fin.close();
    fout.close();
    if(found == false){
        cout << "This ID does not exists" << endl;
        getch();
    }else{
        cout << "Student deleted successfully" << endl;
        getch();
    }

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

void Student::modifyStudent(){
    int id;
    showAllStudents();
    getch();
    bool found = false;
    cout << "Enter roll no of student to modify: ";
    cin >> id;
    cout << "Enter new contact number: ";
    char contact[20];
    fflush(stdin);
    gets(contact);
    fstream file;
    file.open("student.dat", ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    if(!file){
        cout << "File does not exists\n";
    }else{
        file.read((char*)this, sizeof(*this));
        while(file.eof() == 0){
            if(this->rollNo == id){
                found = true;
                strcpy(this->contactNumber, contact);
                file.seekp(file.tellp() - sizeof(*this));
                file.write((char*)this, sizeof(*this));
            }
            file.read((char*)this, sizeof(*this));
        }
    }
    file.close();
    if(found == true){
        cout << "Data updated successfully" << endl;
        Sleep(3000);
    }else{
        cout << "This Roll No does not exists" << endl;
        Sleep(3000);
    }
}

#endif