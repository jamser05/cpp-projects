#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

class Student {
public:
    string name;
    int roll_number;
    int age;

    Student(string name, int roll_number, int age) {
        this -> name = move(name);
        this -> roll_number = roll_number;
        this -> age = age;
    }

    void display() const {
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << roll_number << "\n";
        cout << "Age: " << age << "\n";
    }

    void save_to_file(ofstream &out) const {
        out << name << "\n" << roll_number << "\n" << age << "\n";
    }

    static Student load_from_file(ifstream &in) {
        string name;
        int roll_number;
        int age;

        getline(in, name);
        in >> roll_number;
        in >> age;
        in.ignore();

        return Student(name, roll_number, age);
    }
};

void add_student(vector<Student> &students) {
    string name;
    int roll_number;
    int age;

    cout << "Enter student's name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> roll_number;
    cout << "Enter age: ";
    cin >> age;

    students.emplace_back(name, roll_number, age);
}

void display_all_students(const vector<Student> &students) {
    for (const auto &student :  students) {
        student.display();
        cout << "-------------------\n";
    }
}


void save_students_to_file(const vector<Student> &students, const string &filename) {
    ofstream out(filename);

    if (!out.is_open()) {
        cout << "Failed to open the file for writing!\n";
        return;
    }

    for (const auto &student: students) {
        student.save_to_file(out);
    }

    out.close();
}

void load_students_from_file(vector<Student> &students, const string &filename) {
    ifstream in(filename);

    if (!in.is_open()) {
        cout << "No previous records found. Starting with an empty list.\n";

        return;
    }

    while (!in.eof()) {
        students.push_back(Student::load_from_file(in));
    }

    in.close();
}

int main() {
    vector<Student> students;
    string filename = "students.txt";

    load_students_from_file(students, filename);

    while (true) {
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                add_student(students);
                break;
            case 2:
                display_all_students(students);
                break;
            case 3:
                save_students_to_file(students, filename);
                break;
            defualt:
        }
    }
}

