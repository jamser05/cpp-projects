//
// Created by melap on 7/16/2024.
//

#include <iostream>
using namespace std;

class Calculator {
    public:
    int a, b, c;
    char op;

    void getValue1(); void getValue2();
    // bool exit();
    void getOperation();
    void add();
    void subtract();
    void divide();
    void mutiply();
} obj;

int calculator_app() {

    while (true){
        cout << "ENTER 'q' TO EXIT\n";

        obj.getValue1();

        if (obj.a == 'q' || obj.b == 'q' || obj.c == 'q') {
            break;
        }

        obj.getOperation();

        if (obj.op == '=') {
            cout << "\nFinal answer: " << obj.a << endl;
            break;
        }

        obj.getValue2();

        if (obj.op == '+') {
            obj.add();
        }
        if (obj.op == '-') {
            obj.subtract();
        }
        if (obj.op == '*') {
            obj.mutiply();
        }
        if (obj.op == '/') {
            obj.divide();
            }
    }
    return 0;
}

bool valid_number(char number) {
    return isdigit(number) || number == 'q';
}

void Calculator :: getValue1() {
    char input;
    do {
        cout << "Enter the first value: ";

        cin >> input;
        if (input == 'q') {
            exit(0);
        }

        if (!valid_number(input)) {
            cin.clear();
            cout << "Invalid input, try putting a number\n";
        } else {
            a = input - '0';
            break;
        }
    } while (true);
}

void Calculator :: getValue2() {
    char input;
    do {
        cout << "Enter the second value: ";

        cin >> input;

        if (input == 'q') {
            exit(0);
        }

        if (!valid_number(input)) {
            cin.clear();
            cout << "Invalid input, try putting a number\n";
        } else {
            b = input - '0';
            break;
        }
    } while (true);
}

bool valid_operation(char operation) {
    switch (operation) {
        case '/':
            return true;
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '=':
            return true;
        case 'q':
            return true;
    }

    return false;
}

void Calculator :: getOperation() {
    do {
        cout << "Enter the an operation: ";
        cin >> op;

        if (!valid_operation(op)) {
            cin.clear();
            cout << "Invalid input, try entering a valid operation\n";
        } else {
            break;
        }
    } while (true);
}

void Calculator :: add() {
    c = a + b;
    cout << a  << " + " << b << " = " << c << endl;
    a = c;
    b = 0;
}

void Calculator :: subtract() {
    c = a - b;
    cout << a  << " - " << b << " = " << c << endl;
    a = c;
    b = 0;
}

void Calculator :: mutiply() {
    c = a * b;
    cout << a  << " * " << b << " = " << c << endl;
    a = c;
    b = 0;
}
void Calculator :: divide() {
    c = a / b;
    cout << a  << " / " << b << " = " << c << endl;
    a = c;
    b = 0;
}