#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //range based loop
#include <fstream>
#include <sstream> //to load data from file
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marksMath, marksScience, marksEnglish;

public:
    // Constructor
    Student(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marksMath = m1;
        marksScience = m2;
        marksEnglish = m3;
    }

    int getRollNo() {
        return rollNo;
    }

    string getName() {
        return name;
    }

    float getAverage() {
        return (marksMath + marksScience + marksEnglish) / 3;
    }

    char getGrade() {
        float avg = getAverage();
        if (avg >= 90) return 'A';
        else if (avg >= 75) return 'B';
        else if (avg >= 60) return 'C';
        else return 'D';
    }

    bool isPass() {
        return marksMath >= 35 && marksScience >= 35 && marksEnglish >= 35 && getAverage() >= 40;
    }

    void updateMarks(float m1, float m2, float m3) {
        marksMath = m1;
        marksScience = m2;
        marksEnglish = m3;
    }

    void updateName(string newName) {
        name = newName;
    }

    void displayReport() {
        float total = marksMath + marksScience + marksEnglish;
        float average = total / 3;

        cout << "\n----------------------------";
        cout << "\nRoll No: " << rollNo;
        cout << "\nName   : " << name;
        cout << "\nMath   : " << marksMath;
        cout << "\nScience: " << marksScience;
        cout << "\nEnglish: " << marksEnglish;
        cout << "\nTotal  : " << total;
        cout << "\nAverage: " << average;
        cout << "\nGrade  : " << getGrade();
        cout << "\nStatus : " << (isPass() ? "Pass" : "Fail");
        cout << "\n----------------------------\n";
    }

    string toCSV() {
        return to_string(rollNo) + "," + name + "," + to_string(marksMath) + "," + to_string(marksScience) + "," + to_string(marksEnglish) + "," + to_string(getAverage()) + "," + getGrade();
    }
};

vector<Student> studentList;
void loadFromFile() {
    ifstream file("students.csv");
    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string rollStr, name, m1Str, m2Str, m3Str, avgStr, gradeStr;

        getline(ss, rollStr, ',');
        getline(ss, name, ',');
        getline(ss, m1Str, ',');
        getline(ss, m2Str, ',');
        getline(ss, m3Str, ',');

        int roll = stoi(rollStr);
        float m1 = stof(m1Str);
        float m2 = stof(m2Str);
        float m3 = stof(m3Str);

        studentList.push_back(Student(roll, name, m1, m2, m3));
    }

    file.close();
    cout << "\nData loaded from students.csv\n";
}

void saveToFile() {
    ofstream file("students.csv");
    file << "RollNo,Name,Math,Science,English,Average,Grade\n";
    for (auto &s : studentList) {
        file << s.toCSV() << "\n";
    }
    file.close();
    cout << "\nData saved to students.csv\n";
}

void addStudent() {
    int roll;
    string name;
    float m1, m2, m3;

    cout << "\nEnter Roll No: ";
    cin >> roll;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter marks in Math, Science and English: ";
    cin >> m1 >> m2 >> m3;

    Student s(roll, name, m1, m2, m3);
    studentList.push_back(s);
    cout << "Student added successfully!\n";
}

void displayAll() {
    if (studentList.empty()) {
        cout << "No students to display.\n";
        return;
    }

    for (auto &student : studentList) {
        student.displayReport();
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll No to search: ";
    cin >> roll;
    bool found = false;

    for (auto &student : studentList) {
        if (student.getRollNo() == roll) {
            student.displayReport();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll No to delete: ";
    cin >> roll;
    bool found = false;

    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->getRollNo() == roll) {
            studentList.erase(it);
            cout << "Student deleted successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void updateStudent() {
    int roll;
    cout << "\nEnter Roll No to update: ";
    cin >> roll;
    bool found = false;

    for (auto &student : studentList) {
        if (student.getRollNo() == roll) {
            string newName;
            float m1, m2, m3;

            cout << "Enter new name (or press Enter to keep current): ";
            cin.ignore();
            getline(cin, newName);

            cout << "Enter new marks (Math, Science, English): ";
            cin >> m1 >> m2 >> m3;

            if (!newName.empty()) {
                student.updateName(newName);
            }
            student.updateMarks(m1, m2, m3);
            cout << "Student updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void displayCount() {
    cout << "\nTotal number of students: " << studentList.size() << endl;
}

void sortStudentsByRoll() {
    sort(studentList.begin(), studentList.end(), [](Student &a, Student &b) {
        return a.getRollNo() < b.getRollNo();
    });
    cout << "Students sorted by Roll Number.\n";
}

void searchByName() {
    string key;
    cout << "\nEnter name to search: ";
    cin.ignore();
    getline(cin, key);
    bool found = false;

    for (auto &student : studentList) {
        if (student.getName().find(key) != string::npos) {
            student.displayReport();
            found = true;
        }
    }

    if (!found) cout << "No matching name found.\n";
}

int main() {
    loadFromFile();

    int choice;
    do {
        cout << "\n====== Student Report Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Count Total Students\n";
        cout << "7. Sort Students by Roll No\n";
        cout << "8. Search Student by Name\n";
        cout << "9. Save to CSV File\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: displayCount(); break;
            case 7: sortStudentsByRoll(); break;
            case 8: searchByName(); break;
            case 9: saveToFile(); break;
            case 10: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
