#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

Snake snake_obj;

void show_score() {
    cout << "Final Score: " << snake_obj.score << "\n";
}

void start_snake_game() {
    char key_pressed;

    snake_obj.get_snake_location();
    snake_obj.get_food_location();
    snake_obj.make_board();

    while (true) {
        if (snake_obj.out_of_bounds() || snake_obj.snake_hit_itself()) {
            show_score();
            break;
        }

        snake_obj.eat_food(key_pressed);

        if (_kbhit()) {
            key_pressed = _getch();
        }

        snake_obj.update_snake_position(key_pressed);
        snake_obj.preview_board();

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    start_snake_game();
    return 0;
}
