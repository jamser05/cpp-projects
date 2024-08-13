#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <random>

using namespace std;

typedef vector<pair<int, int>> snake_rep;
typedef pair<int, int> food_rep;
typedef vector<vector<char>> board_rep;
typedef char symbol;

int DIMENSION = 20;

class Snake {
public:
    snake_rep snake; symbol snake_symbol = '*';
    food_rep food; symbol food_symbol = 'O';
    board_rep board;

    Snake() {
        board.resize(DIMENSION, vector<char>(DIMENSION));
    }

    static int generate_random_position(int lower_bound, int upper_bound) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(lower_bound, upper_bound);

        return distr(gen);
    }

    void get_snake_location() {
        int snake_x_pos = generate_random_position(1, DIMENSION - 2);
        int snake_y_pos = generate_random_position(1, DIMENSION - 2);

        snake.emplace_back(snake_x_pos, snake_y_pos);
    }

    bool food_eaten() {
        if (snake[0].first == food.first && snake[0].second == food.second) {
            snake.emplace_back(snake[0].first, snake[0].second + 1);
            get_food_location();
            return true;
        }

        return false;
    }

    void get_food_location() {
        int food_x_pos = generate_random_position(1, DIMENSION - 2);
        int food_y_pos = generate_random_position(1, DIMENSION - 2);

        food.first = food_x_pos; food.second = food_y_pos;
    }

    void make_board() {
        for (int row = 0; row < DIMENSION; row++) {
            for (int column = 0; column < DIMENSION; column++) {
                if (row == 0 || row == DIMENSION -1 || column == 0 || column == DIMENSION - 1) {
                    board[row][column] = '#';
                } else {
                    board[row][column] = ' ';
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
                if (row == food.first && column == food.second) {
                    cout << food_symbol;
                } else if (row == snake[0].first && column == snake[0].second) {
                    cout << snake_symbol;
                } else {
                    cout << board[row][column];
                }
            }
            cout << "\n";
        }
    }

} snake_obj;

void start_snake_game() {
    char key_pressed;
    snake_obj.get_snake_location();

    while (true) {
        if (_kbhit()) {
            snake_obj.preview_board();

            key_pressed = _getch();

            switch (key_pressed) {
                case 'w':
                    for (int part = 0; part < snake_obj.snake.size(); part++) {
                        snake_obj.snake[part].first -= 1;
                    }
                break;
                case 's':
                    for (int part = 0; part < snake_obj.snake.size(); part++) {
                        snake_obj.snake[part].first += 1;
                    }
                break;
                case 'd':
                    for (int part = 0; part < snake_obj.snake.size(); part++) {
                        snake_obj.snake[part].second += 1;
                    }
                break;
                case 'a':
                    for (int part = 0; part < snake_obj.snake.size(); part++) {
                        snake_obj.snake[part].second -= 1;
                    }
                break;
                default:
                    cout << "Not a valid movement";
                break;
            }
        }
    }
}

int main() {
    start_snake_game();

    return 0;
}