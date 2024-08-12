#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>

using namespace std;

typedef vector<pair<int, int>> snake_rep;
typedef pair<int, int> food_rep;
typedef vector<vector<char>> board_rep;

int DIMENSION = 20;

class Snake {
public:
    snake_rep snake;
    food_rep food;
    board_rep board;

    Snake() {
        board.resize(DIMENSION, vector<char>(DIMENSION));
    }

    void make_board() {
        for (int row = 0; row < DIMENSION; row++) {
            for (int col = 0; col < DIMENSION; col++) {
                if (row == 0 || row == DIMENSION - 1) {
                    board[row][col] = '#';
                } else if (col == 0 || col == DIMENSION - 1) {
                    board[row][col] = '#';
                } else {
                    board[row][col] = ' ';
                }
            }
        }
    }

    void preview_board() {
        make_board();
        cout << "Welcome to Snake\n";
        cout << "================\n";

        for (int row = 0; row < DIMENSION; row++) {
            for (int column = 0; column < DIMENSION; column++) {
                cout << board[row][column];
            }
            cout << "\n";
        }
    }

} snake;

void start_snake_game() {
    // while (true) {
    //
    // }
}

int main() {
    snake.preview_board();

    return 0;
}