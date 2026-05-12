#include <iostream>
#include <string>

using namespace std;

// Functions
void login();
void addStudent(string *names, int *ids, int &count);
void showStudents(string *names, int *ids, int *grades, int count);
void addGrades(string *names, int *grades, int count);

int main() {

    const int SIZE = 100;

    string studentNames[SIZE];
    int studentIDs[SIZE];
    int studentGrades[SIZE] = {0};

    int count = 0;
    int choice;

    login();

    do {

        cout << "\n===== Professor Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Add Grades\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addStudent(studentNames, studentIDs, count);
                break;

            case 2:
                showStudents(studentNames, studentIDs,
                             studentGrades, count);
                break;

            case 3:
                addGrades(studentNames, studentGrades, count);
                break;

            case 4:
                cout << "\nExiting the system...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}

// Login Function
void login() {

    string username, password;

    cout << "===== University Professor Login =====\n";

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter your password: ";
    cin >> password;

    if(username == "admin" && password == "1234") {

        cout << "\nWelcome Professor " << username << "!\n";
    }
    else {

        cout << "\nIncorrect username or password!\n";
        exit(0);
    }
}

// Add Student Function
void addStudent(string *names, int *ids, int &count) {

    cout << "\nEnter student name: ";
    cin >> *(names + count);

    cout << "Enter student ID: ";
    cin >> *(ids + count);

    count++;

    cout << "Student added successfully!\n";
}

// Show Students Function
void showStudents(string *names, int *ids,
                  int *grades, int count) {

    cout << "\n===== Student List =====\n";

    for(int i = 0; i < count; i++) {

        cout << "\nStudent " << i + 1 << endl;

        cout << "Name: " << *(names + i) << endl;
        cout << "ID: " << *(ids + i) << endl;
        cout << "Grade: " << *(grades + i) << endl;

        if(*(grades + i) >= 50)
            cout << "Status: Pass\n";
        else
            cout << "Status: Fail\n";
    }
}

// Add Grades Function
void addGrades(string *names, int *grades, int count) {

    cout << "\n===== Add Grades =====\n";

    for(int i = 0; i < count; i++) {

        cout << "Enter grade for "
             << *(names + i) << ": ";

        cin >> *(grades + i);
    }

    cout << "Grades added successfully!\n";
}
