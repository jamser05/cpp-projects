#include "Snake.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

int DIMENSION = 18;

Snake::Snake() {
    board.resize(DIMENSION, vector<char>(DIMENSION));
}

int Snake::generate_random_position(int lower_bound, int upper_bound) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(lower_bound, upper_bound);
    return distr(gen);
}

bool Snake::out_of_bounds() {
    if (snake[0].first < 1 || snake[0].first >= DIMENSION - 1 || snake[0].second < 1 || snake[0].second >= DIMENSION - 1) {
        return true;
    }
    return false;
}

bool Snake::snake_hit_itself() {
    for (int index = 1; index < snake.size(); index++) {
        if (snake[0].first == snake[index].first && snake[0].second == snake[index].second) {
            return true;
        }
    }
    return false;
}

void Snake::get_snake_location() {
    int snake_x_pos = generate_random_position(1, DIMENSION - 2);
    int snake_y_pos = generate_random_position(1, DIMENSION - 2);
    snake.emplace_back(snake_x_pos, snake_y_pos);
}

bool Snake::is_food_eaten() {
    if (snake[0].first == food.first && snake[0].second == food.second) {
        return true;
    }
    return false;
}

void Snake::eat_food(char direction) {
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
        score++;
        get_food_location();
    }
}

void Snake::get_food_location() {
    int food_x_pos = generate_random_position(1, DIMENSION - 2);
    int food_y_pos = generate_random_position(1, DIMENSION - 2);
    food.first = food_x_pos; food.second = food_y_pos;
}

void Snake::make_board() {
    for (int row = 0; row < DIMENSION; row++) {
        for (int column = 0; column < DIMENSION; column++) {
            if (row == 0 || row == DIMENSION -1 || column == 0 || column == DIMENSION - 1) {
                board[row][column] = border_symbol;
            } else {
                board[row][column] = empty_space;
            }
        }
    }
}

void Snake::update_snake_position(char direction) {
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
        default:
            break;
    }
}

void Snake::preview_board() {
    for (int row = 0; row < DIMENSION; row++) {
        for (int column = 0; column < DIMENSION; column++) {
            if (row == food.first && column == food.second) {
                cout << food_symbol;
            }  else {
                bool is_snake_part = false;
                for (int index = 0; index < snake.size(); index++) {
                    if (snake[index].first == row && snake[index].second == column) {
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
