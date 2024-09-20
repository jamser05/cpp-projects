#include "matrix_library.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>

using namespace std;

#define TWO_DIMENSIONAL_VEC vector<vector<string>>
#define UINT unsigned int

struct st_matrix_dim {
    int rows, columns;
};

class Matrix {
public:
    ~Matrix();
    Matrix();

    void initialize(string var, UINT rowSize, UINT colSize, string strVal);
    void setVal(string var, UINT rowNum, UINT colNum, string strVal);

    string getVal(string var, UINT rowNum, UINT colNum);

    UINT getRows(string var);

    UINT getColumns(string var);

    void print_matrix(string var);


private:
    map<string, TWO_DIMENSIONAL_VEC> store;

    map<string, bool> lookup;
    map<string, st_matrix_dim> matrix_dim;
};

Matrix::Matrix() { }
Matrix::~Matrix() { }

void Matrix::initialize(string var, unsigned int rowSize, unsigned int colSize, string strVal) {
   TWO_DIMENSIONAL_VEC vec_matrix;
    vec_matrix.resize(rowSize + 1);

    for (UINT i = 0; i < vec_matrix.size(); i++) {
        vec_matrix[i].resize(colSize + 1, strVal);
    }

    st_matrix_dim s;
    s.columns = colSize;
    s.rows = rowSize;

    this -> store[var] = vec_matrix;
    this -> matrix_dim[var] = s;

    lookup[var] = true;
}

UINT Matrix::getRows(string var) {
    return this -> matrix_dim[var].rows;
}


UINT Matrix::getColumns(string var) {
    return this -> matrix_dim[var].columns;
}

void Matrix::setVal(string var, unsigned int rowNum, unsigned int colNum, string strVal) {
    if (rowNum > getRows(var) || colNum > getColumns(var)) {
        cout << "Cannot setdata because it's outside the boundary of the array.\n";
        return;
    }

    this -> store[var][rowNum][colNum] = strVal;
}

string Matrix::getVal(string var,UINT rowNum, UINT colNum) {
    if (rowNum > getRows(var) || colNum > getColumns(var)) {
        cout << "Cannot setdata because it's outside the boundary of the array.\n";
        return "";
    }

    return this->store[var][rowNum][colNum];
}

void Matrix::print_matrix(string var) {
    if (lookup[var]) {
        UINT rows = this->getRows(var);
        UINT cols = this->getColumns(var);

        cout << "Matrix:" << var << endl;
        cout << "rows:" << rows << " cols:" << cols << endl;

        for (UINT i = 0; i < rows; i++) {
            for (UINT j = 0; j < cols; j++) {
                cout << "[" << this->getVal(var, i, j) << "] ";
            }

            cout << endl;
        }
    }
}

int main() {
    unique_ptr<Matrix> x (new Matrix());

    x->initialize("a", 5, 5, " ");
    x->initialize("b", 10, 10, " ");
    x->initialize("c", 3, 3, " ");

    x->setVal("a", 5, 2, "apple");
    x->setVal("a", 1, 4, "pineapple");

    cout << "val:" << x->getVal("a", 5, 2) << endl;
    cout << "val:" << x->getVal("a", 1, 4) << endl;

    x->print_matrix("a");

    x->setVal("b", 4, 2, "sugar");
    x->setVal("b", 2, 4, "pie");

    x->print_matrix("b");

    x->setVal("c", 2, 3, "pear");
    x->setVal("c", 1, 2, "lemon");

    x->print_matrix("c");
}