#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int roll_number;
    int age;

    explicit Student(string name = "", int roll_number = 0, int age = 0): name(move(name)), roll_number(roll_number), age(age) {}

    void display() const {
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << roll_number << "\n";
        cout << "Age: " << age << "\n";
    }

    void save_to_file(ofstream &out) const {
        out << name << "\n" << roll_number << "\n" << age << "\n";
    }

    static bool load_from_file(ifstream &in, Student &student) {
        if (!getline(in, student.name)) return false;
        if (!(in >> student.roll_number)) return false;
        if (!(in >> student.age)) return false;
        in.ignore();

        return true;
    }
};

void add_student(vector<Student> &students) {
    string name;
    int roll_number;
    int age;

    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> roll_number;
    cout << "Enter age: ";
    cin >> age;

    students.emplace_back(name, roll_number, age);
}

void delete_record(vector<Student> &students, const string &filename) {
    int id;
    cout << "Enter student's roll number to delete:";
    cin >> id;

    auto it = remove_if(students.begin(), students.end(), [id](const Student &student) {
        return student.roll_number == id;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student with roll number " << id << " has been deleted.\n";
    } else {
        cout << "No student found with roll number " << id << ".\n";
    }

    ofstream out(filename);

    if (!out.is_open()) {
        cout << "Failed to open the file for writing!\n";
        return;
    }

    for (const auto &student : students) {
        student.save_to_file(out);
    }

    out.close();
}

void display_all_students(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    for (const auto &student : students) {
        student.display();
        cout << "-------------------\n";
    }
}

void save_students_to_file(const vector<Student> &students, const string &filename) {
    ofstream out(filename, ios::trunc);

    if (!out.is_open()) {
        cout << "Failed to open the file for writing!\n";
        return;
    }

    for (const auto &student : students) {
        student.save_to_file(out);
    }
}

void load_students_from_file(vector<Student> &students, const string &filename) {
    ifstream in(filename);

    if (!in.is_open()) {
        cout << "No previous records found. Starting with an empty list.\n";
        return;
    }

    while (true) {
        string name;
        int roll_number;
        int age;

        if (!getline(in, name)) {
            break;
        }
        if (!(in >> roll_number)) {
            break;
        }
        if (!(in >> age)) {
            break;
        }

        if (empty(name)) {
            break;
        }
        in.ignore();

        students.emplace_back(name, roll_number, age);
    }

    in.close();
}

void start_student_managament_system() {
    vector<Student> students;
    string filename = "students.txt";

    load_students_from_file(students, filename);

    while (true) {
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
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
                delete_record(students, filename);
            break;
            case 4:
                save_students_to_file(students, filename);
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
}

