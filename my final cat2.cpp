#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include<iomanip>

using namespace std;

class Student {
public:
    int timeline;
    string name;
    int adm_no;
    int eng;
    int math;
    int kisw;
    int cre;
    int chem;
    int bio;
    int phy;

    Student(string n, int adm, int e, int m, int k, int c, int ch, int b, int p)
        : name(n), adm_no(adm), eng(e), math(m), kisw(k), cre(c), chem(ch), bio(b), phy(p) {}

    void readtime() {
        cout << "Input the year and semester of examination: ";
        cin >> timeline;
    }

    int getTimeline() const {
        return timeline;
    }
};

class Year12 : public Student {
public:
    int ObjectOrientedProgramming;
    int Assembly;
    int SoftwareDesign;
    int ComputerVision;

    Year12(string n, int a, int O, int A, int SD, int CV)
        : Student(n, a, 0, 0, 0, 0, 0, 0, 0), // Initialize base class with dummy values
          ObjectOrientedProgramming(O), Assembly(A), SoftwareDesign(SD), ComputerVision(CV) {}
};

class Fee {
public:
    int RequiredFee, PaidFee, AdmNo, year, semester;

    Fee(int r, int p, int a, int y, int s)
        : RequiredFee(r), PaidFee(p), AdmNo(a), year(y), semester(s) {}

    int RemainingFee() const {
        return RequiredFee - PaidFee;
    }
};

class Feestatement {
private:
    vector<Fee> fee;

public:
    void addFee(const Fee& f) {
        fee.push_back(f);
    }

    void displayFee(int adm_no) const {
        for (vector<Fee>::const_iterator it = fee.begin(); it != fee.end(); ++it) {
            if (it->AdmNo == adm_no) {
                cout << "Admission Number: " << it->AdmNo << '\n'
                     << "Required Fee: " << it->RequiredFee << '\n'
                     << "Paid Fee: " << it->PaidFee << '\n'
                     << "Remaining Fee: " << it->RemainingFee() << '\n';
                return;
            }
        }
        cout << "Student with Adm No " << adm_no << " not found.\n";
    }

    void payFee(int adm_no, int amount) {
        for (vector<Fee>::iterator it = fee.begin(); it != fee.end(); ++it) {
            if (it->AdmNo == adm_no) {
                it->PaidFee += amount;
                cout << "Payment successful. New Paid Fee: " << it->PaidFee << '\n'
                     << "Remaining Fee: " << it->RemainingFee() << '\n';
                return;
            }
        }
        cout << "Student with Adm No " << adm_no << " not found.\n";
    }
};

class Person {
public:
    string FirstName, LastName, course, password;
    int AdmNo;

    Person(string f, string l, string c, string p, int A)
        : FirstName(f), LastName(l), course(c), password(p), AdmNo(A) {}

    void logInDetails() {
        cout << "Admission Number: ";
        cin >> AdmNo;
        cout << "Password: ";
        cin >> password;
    }

    void RegistrationDetails() {
        cout << "Put your First name: ";
        cin >> FirstName;
        cout << "Put your Last name: ";
        cin >> LastName;
        cout << "Put your Admission Number (No letters): ";
        cin >> AdmNo;
        cout << "Put your Password: ";
        cin >> password;
    }
};

class Teacher : public Person {
public:
    Teacher(string f, string l, string c, string p, int A)
        : Person(f, l, c, p, A) {}

    // No need to override logInDetails or RegistrationDetails unless their behavior needs to change
};

class Table {
private:
    vector<Student> students;
    vector<Year12> year12;
    vector<Teacher> teachers;

public:
    // Add or register new teacher
    void addTeacher(const Teacher& teacher) {
        teachers.push_back(teacher);
    }

    // Add or register new student
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Add new results for year
    void addYear12(const Year12& year12Record) {
        year12.push_back(year12Record);
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }

        // Print table header
        cout << "Name\tAdm No\tEng\tMath\tKisw\tCRE\tChem\tBio\tPhy\n";
        cout << "----------------------------------------------------------------\n";

        // Print student details
        for (vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
            cout << it->name << '\t'
                 << it->adm_no << '\t'
                 << it->eng << '\t'
                 << it->math << '\t'
                 << it->kisw << '\t'
                 << it->cre << '\t'
                 << it->chem << '\t'
                 << it->bio << '\t'
                 << it->phy << '\n';
        }
    }

    void displayStudentDetails(int adm_no) const {
        for (vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
            if (it->adm_no == adm_no) {
                cout << "Name: " << it->name << '\n'
                     << "Adm No: " << it->adm_no << '\n'
                     << "Eng: " << it->eng << '\n'
                     << "Math: " << it->math << '\n'
                     << "Kisw: " << it->kisw << '\n'
                     << "CRE: " << it->cre << '\n'
                     << "Chem: " << it->chem << '\n'
                     << "Bio: " << it->bio << '\n'
                     << "Phy: " << it->phy << '\n';
                return;
            }
        }
        cout << "Student with Adm No " << adm_no << " not found.\n";
    }

    void displayYear12(int adm_no) const {
        for (vector<Year12>::const_iterator it = year12.begin(); it != year12.end(); ++it) {
            if (it->adm_no == adm_no) {
                cout << "Name: " << it->name << '\n'
                     << "Adm No: " << it->adm_no << '\n'
                     << "OOP: " << it->ObjectOrientedProgramming << '\n'
                     << "Assembly: " << it->Assembly << '\n'
                     << "Software Design: " << it->SoftwareDesign << '\n'
                     << "Computer Vision: " << it->ComputerVision << '\n';
                return;
            }
        }
        cout << "Student with Adm No " << adm_no << " not found.\n";
    }

    void displayAllYear12() const {
        if (year12.empty()) {
            cout << "No Year 12 students found.\n";
            return;
        }

        // Print table header
        cout << "Name\tAdm No\tOOP\tAssembly\tSoftware Design\tComputer Vision\n";
        cout << "-------------------------------------------------------------\n";

        // Print student details
        for (vector<Year12>::const_iterator it = year12.begin(); it != year12.end(); ++it) {
            cout << it->name << '\t'
                 << it->adm_no << '\t'
                 << it->ObjectOrientedProgramming << '\t'
                 << it->Assembly << '\t'
                 << it->SoftwareDesign << '\t'
                 << it->ComputerVision << '\n';
        }
    }
};

class MainPage {
private:
    vector<Person> person;
    Feestatement feeStatement;
    vector<Teacher> teachers;

    Table table; // Adding Table instance

public:
    void addPerson(const Person& p) {
        person.push_back(p);
    }

    void addTeacher(const Teacher& t) {
        teachers.push_back(t);
    }

    void LogIn(int adm_no, const string& password) {
        for (vector<Person>::iterator it = person.begin(); it != person.end(); ++it) {
            if (it->AdmNo == adm_no && it->password == password) {
                cout << "WELCOME BACK " << it->FirstName << " " << it->LastName << endl;
                displayWelcomeMessage(it->FirstName, it->LastName, adm_no);
                system("cls");
                return;
            } else if (it->AdmNo != adm_no && it->password == password) {
                cout << "The admission number is wrong" << endl;
                system("cls");
                return;
            } else if (it->AdmNo == adm_no && it->password != password) {
                cout << "The password is wrong" << endl;
                system("cls");
                return;
            }
        }
        cout << "The details are wrong" << endl;
    }

    void TeacherLogIn(int adm_no, const string& password) {
        for (vector<Teacher>::const_iterator it = teachers.begin(); it != teachers.end(); ++it) {
            if (it->AdmNo == adm_no && it->password == password) {

                cout << "WELCOME BACK TEACHER " << it->FirstName << " " << it->LastName << endl;
                displayTeacherPage(it->FirstName, it->LastName, adm_no);
                return;
            } else if (it->AdmNo != adm_no && it->password == password) {
                cout << "The Teaching number is wrong" << endl;
                return;
            } else if (it->AdmNo == adm_no && it->password != password) {
                cout << "The password is wrong" << endl;
                return;
            }
        }
        cout << "The details are wrong" << endl;
    }

    void displayWelcomeMessage(const string& FirstName, const string& lastName, int adm_no) {
        cout << "Welcome to the Zetech University Portal, " << FirstName << " " << lastName << "!" << endl;

        while (true) {
            int yourchoice;
            cout << "1. View results" << endl;
            cout << "2. Check fee statement" << endl;
            cout << "3. Pay fees" << endl;
            cout << "4. Exit" << endl;
            cout << "Input your choice: ";
            cin >> yourchoice;

            switch (yourchoice) {
            case 1: {
                Student dummyStudent("", adm_no, 0, 0, 0, 0, 0, 0, 0); // Temporarily initializing Student object
                dummyStudent.readtime();
                if (dummyStudent.getTimeline() == 12) {
                    table.displayYear12(adm_no);
                    system("cls");
                } else {
                    cout << "The time is not yet in the database" << endl;
                    system("cls");
                }
                break;
            }
            case 2:
                feeStatement.displayFee(adm_no);
                break;
            case 3: {
                int amount;
                cout << "Enter amount to pay: ";
                cin >> amount;

                feeStatement.payFee(adm_no, amount);
                system("cls");
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }

    void displayTeacherPage(const string& FirstName, const string& lastName, int adm_no) {
        cout << "Welcome to the Zetech University Portal, " << FirstName << " " << lastName << "!" << endl;

        while (true) {
            int yourchoice;
            cout << "1. Display all Year 12 results" << endl;
            cout << "2. Display all student details" << endl;
            cout << "3. Add new Year 12 results" << endl;
            cout << "4. Add new student details" << endl;
            cout << "5. Exit" << endl;
            cout << "Input your choice: ";
            cin >> yourchoice;

            switch (yourchoice) {
            case 1: {
                cout << "Complete Table:\n";
                table.displayAllYear12();
                break;
            }
            case 2:
                table.displayAllStudents();
                break;
            case 3: {
                string name;
                int adm_no, O, A, SD, CV;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter admission number: ";
                cin >> adm_no;
                cout << "Enter Object-Oriented Programming marks: ";
                cin >> O;
                cout << "Enter Assembly marks: ";
                cin >> A;
                cout << "Enter Software Design marks: ";
                cin >> SD;
                cout << "Enter Computer Vision marks: ";
                cin >> CV;
                Year12 newYear12(name, adm_no, O, A, SD, CV);
                table.addYear12(newYear12);
                system("cls");
                cout << "Year 12 results added successfully.\n";
                break;
            }
            case 4: {
                string name;
                int adm_no, eng, math, kisw, cre, chem, bio, phy;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter admission number: ";
                cin >> adm_no;
                cout << "Enter English marks: ";
                cin >> eng;
                cout << "Enter Math marks: ";
                cin >> math;
                cout << "Enter Kiswahili marks: ";
                cin >> kisw;
                cout << "Enter CRE marks: ";
                cin >> cre;
                cout << "Enter Chemistry marks: ";
                cin >> chem;
                cout << "Enter Biology marks: ";
                cin >> bio;
                cout << "Enter Physics marks: ";
                cin >> phy;
                Student newStudent(name, adm_no, eng, math, kisw, cre, chem, bio, phy);
                table.addStudent(newStudent);
                system("cls");
                cout << "Student added successfully.\n";
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }
    void showLoading(int duration) {
        const int dotCount = 5; // Number of dots to show
        const int delay = 500;  // Delay between each frame in milliseconds

        // Get the start time
        chrono::steady_clock::time_point startTime = chrono::steady_clock::now();
        // Calculate the end time based on duration
        chrono::steady_clock::time_point endTime = startTime + chrono::seconds(duration);
        cout << "please wait as the system loads" << endl;

        while (chrono::steady_clock::now() < endTime) {
            for (int i = 0; i <= dotCount; ++i) {
                string loading;
                for (int j = 0; j < i; ++j) {
                    loading += ".";
                }
                cout << "\r" << loading << flush; // Move cursor back to start of line
                this_thread::sleep_for(chrono::milliseconds(delay)); // Adjust speed here
            }
            // Clear the line
            cout << "\r" << string(dotCount, ' ') << "\r" << flush;
        }

        cout << "Done!" << endl; // Print done message
    }
};

int main() {
    cout << "        ::::::::::::::::::::::::::::::::::::" << endl;
    cout << "        ::                                ::" << endl;
    cout << "        ::    ZETECH UNIVERSITY PORTAL    ::" << endl;
    cout << "        ::                                ::" << endl;
    cout << "        ::::::::::::::::::::::::::::::::::::" << endl;
    cout << "" << endl;
    cout << "" << endl;


    int choice;
    MainPage mainPage;
    mainPage.showLoading(10);
    system("cls");


    while (true) {
        cout << "1: student Log in" << endl;
        cout << "2: Register as Student" << endl;
        cout << "3: Register as Teacher" << endl;
        cout << "4: teacher Log in" << endl;
        cout << "Input your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int adm_no;
            string password;
            cout << "Enter Admission Number: ";
            cin >> adm_no;
            cout << "Enter Password: ";
            cin >> password;
            system("cls");

            mainPage.LogIn(adm_no, password);
            break;
        }
        case 2: {
            Person newPerson("", "", "", "", 0);
            newPerson.RegistrationDetails();
            mainPage.addPerson(newPerson);
            system("cls");
            break;
        }
        case 3: {
            string name;
            int adm_no;
            string password;
            cout << "Enter your First Name: ";
            cin >> name;
            cout << "Enter your Last Name: ";
            cin >> name;
            cout << "Enter your Teaching Number: ";
            cin >> adm_no;
            cout << "Enter your Password: ";
            cin >> password;
            Teacher newTeacher(name, name, "Teaching", password, adm_no);
            mainPage.addTeacher(newTeacher);
            system("cls");
            break;
        }
        case 4:{
        	int adm_no;
            string password;
            cout << "Enter Teaching Number: ";
            cin >> adm_no;
            cout << "Enter Password: ";
            cin >> password;
            system("cls");
            mainPage.TeacherLogIn(adm_no, password);
			break;
		}
        default: {
            cout << "Invalid choice!" << endl;
            system("cls");
            break;
        }
        }
    }

    return 0;
}
