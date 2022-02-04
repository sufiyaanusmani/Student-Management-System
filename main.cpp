#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "student.h"
using namespace std;

int mainMenu();

int main(){
    int choice;
    Student s;

    while(1){
        choice = mainMenu();
        switch(choice){
            case 1:
                s.setData();
                break;
            case 2:
                s.showAllStudents();
                break;
            case 3:
                s.searchStudent();
                break;
            case 4:
                s.deleteStudent();
                break;
            // case 5:
            //     s.modifyStudent();
            //     break;
            default:
                cout << "Wrong choice entered, please enter a valid choice" << endl;
                Sleep(3000);
        }
    }
    return 0;
}

int mainMenu(){
    int choice;
    system("cls");
    cout << "1. Add Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Delete Student" << endl;
    cout << "5. Modify Student Details" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}