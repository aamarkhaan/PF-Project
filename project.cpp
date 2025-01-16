#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    int age;
    int rollNo;
    string name;
    string phone;
    string email;
};

const int MaxStudents = 20;
Student students[MaxStudents];
int studentCount = 0;

void saveStudentData() 
{
    ofstream file("students.txt");
    for (int i = 0; i < studentCount; ++i) 
    {
        file << students[i].id << " " << students[i].name << " " << students[i].age << " " << students[i].rollNo << " " << students[i].phone << " " << students[i].email << endl;
    }
    file.close();
}

void loadStudentData() 
{
    ifstream file("students.txt");
    studentCount = 0;
    while (file >> students[studentCount].id) 
    {
        file.ignore();
        getline(file, students[studentCount].name);
        file >> students[studentCount].age >> students[studentCount].rollNo;
        file.ignore();
        getline(file, students[studentCount].phone);
        getline(file, students[studentCount].email);
        ++studentCount;
    }
    file.close();
}

void addStudentData() 
{
    if (studentCount >= MaxStudents) 
    {
        cout << "Database is Full" << endl;
        return;
    }

    cout << "Enter student ID : ";
    cin >> students[studentCount].id;
    cin.ignore();
    cout << "Enter Student name : ";
    getline(cin, students[studentCount].name);
    cout << "Enter student age : ";
    cin >> students[studentCount].age;
    cout << "Enter student roll number : ";
    cin >> students[studentCount].rollNo;
    cin.ignore();
    cout << "Enter student phone number : ";
    getline(cin, students[studentCount].phone);
    cout << "Enter student email : ";
    getline(cin, students[studentCount].email);

    ++studentCount;
    saveStudentData();
}

void updateStudentData() 
{
    int id;
    cout << "Enter student ID to update : ";
    cin >> id;

    for (int i = 0; i < studentCount; ++i) 
    {
        if (students[i].id == id) 
        {
            cin.ignore();
            cout << "Enter new name : ";
            getline(cin, students[i].name);
            cout << "Enter new age : ";
            cin >> students[i].age;
            cout << "Enter new roll number : ";
            cin >> students[i].rollNo;
            cin.ignore();
            cout << "Enter new phone number : ";
            getline(cin, students[i].phone);
            cout << "Enter new email : ";
            getline(cin, students[i].email);

            saveStudentData();
            return;
        }
    }
    cout << "Invalid Input" << endl;
}

void deleteStudentData() 
{
    int id;
    cout << "Enter student ID to delete : ";
    cin >> id;

    for (int i = 0; i < studentCount; ++i) 
    {
        if (students[i].id == id) 
        {
            for (int j = i; j < studentCount - 1; ++j) 
            {
                students[j] = students[j + 1];
            }
            --studentCount;

            saveStudentData();
            cout << "Student deleted successfully" << endl;
            return;
        }
    }
    cout << "Invalid Input" << endl;
}

void searchStudentData() 
{
    int id;
    cout << "Enter student ID to search : ";
    cin >> id;

    for (int i = 0; i < studentCount; ++i) 
    {
        if (students[i].id == id) 
        {
            cout << "ID : " << students[i].id << endl;
            cout << "Name : " << students[i].name << endl;
            cout << "Age : " << students[i].age << endl;
            cout << "Roll Number : " << students[i].rollNo << endl;
            cout << "Phone Number : " << students[i].phone << endl;
            cout << "Email : " << students[i].email << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

int main() 
{
    loadStudentData();
    int choice;
    do {
        cout << endl;
        cout << "---  Student Management System  ---" << endl;
        cout << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Exit" << endl;

        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addStudentData();
                break;
            case 2:
                updateStudentData();
                break;
            case 3:
                deleteStudentData();
                break;
            case 4:
                searchStudentData();
                break;
            case 5:
                cout << "Exiting ..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}