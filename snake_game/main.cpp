#include "Snake.h"
#include "Player.h"
#include <conio.h>
#include <chrono>
#include <thread>
#include <bits/ranges_algo.h>

using namespace std;

Snake snake_obj;

void game_over_options(vector<Player> players, int score) {
    string filename = "snake_players_stats.txt";

    cout << "1. Add Player\n";
    cout << "2. Show Leaderboard\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            add_player(players,score);
        break;
        case 2:
            display_leaderboard(players);
        break;
        case 3:
            save_players_to_file(players, filename);
        default:
            game_over_options(players, score);
    }
}

void start_snake_game() {
    vector<Player> players;
    char key_pressed;

    snake_obj.get_snake_location();
    snake_obj.get_food_location();
    snake_obj.make_board();

    while (true) {
        if (snake_obj.out_of_bounds() || snake_obj.snake_hit_itself()) {
            game_over_options(players, snake_obj.score);
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
