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
    snake_rep snake; symbol snake_symbol = '@';
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

    bool out_of_bounds() {
        if (snake[0].first < 1 || snake[0].first >= DIMENSION - 1 || snake[0].second < 1 || snake[0].second >= DIMENSION - 1) {
            return true;
        }

        return false;
    }

    void get_snake_location() {
        int snake_x_pos = generate_random_position(1, DIMENSION - 2);
        int snake_y_pos = generate_random_position(1, DIMENSION - 2);

        snake.emplace_back(snake_x_pos, snake_y_pos);
    }

    bool is_food_eaten() {
        if (snake[0].first == food.first && snake[0].second == food.second) {
            return true;
        }

        return false;
    }

    void eat_food(char direction) {
        if (is_food_eaten()) {
            int new_x = snake.back().first;
            int new_y = snake.back().second;

            switch (direction) {
                case 'w':
                    new_x += 1;
                    break;
                case 's':
                    new_x -= 1;
                    break;
                case 'd':
                    new_y -= 1;
                    break;
                case 'a':
                    new_y += 1;
                    break;
            }

            snake.emplace_back(new_x, new_y);
            get_food_location();
        }
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

    void update_snake_position(char direction) {
        for (int i = snake.size() - 1; i > 0; --i) {
            snake[i] = snake[i - 1];
        }
        switch (direction) {
            case 'w':
                snake[0].first -= 1;
                break;
            case 's':
                snake[0].first += 1;
                break;
            case 'd':
                snake[0].second += 1;
            break;
            case 'a':
                snake[0].second -= 1;
            break;
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
                }  else {
                    bool is_snake_part = false;

                    for (int part = 0; part < snake.size(); part++) {
                        if (snake[part].first == row && snake[part].second == column) {
                            cout << snake_symbol;
                            is_snake_part=true;
                            break;
                        }
                    }

                    if (!is_snake_part) {
                        cout << board[row][column];
                    }
                }


            }
            cout << "\n";
        }
    }

} snake_obj;

void start_snake_game() {
    char key_pressed;
    snake_obj.get_snake_location();
    snake_obj.get_food_location();

    while (true) {
        if (snake_obj.out_of_bounds()) {
            break;
        }

        snake_obj.eat_food(key_pressed);

        if (_kbhit()) {

            key_pressed = _getch();
            snake_obj.preview_board();

        }

        snake_obj.update_snake_position(key_pressed);
        snake_obj.eat_food(key_pressed);
    }
}

int main() {
    start_snake_game();

    return 0;
}