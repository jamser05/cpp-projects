#include "Snake.h"
#include "Player.h"
#include <conio.h>
#include <chrono>
#include <thread>
#include <bits/ranges_algo.h>

using namespace std;

Snake snake_obj;

void start_snake_game() {
    char key_pressed;

    snake_obj.get_snake_location();
    snake_obj.get_food_location();
    snake_obj.make_board();

    while (true) {
        if (snake_obj.out_of_bounds() || snake_obj.snake_hit_itself()) {
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

void player_options(vector<Player> players, int score) {
    string filename = "snake_players_stats.txt";

    load_players_from_file(players, filename);

    cout << "1. Start Game\n";
    cout << "2. Show Leaderboard\n";
    cout << "Enter your choice: \n";

    int choice; cin >> choice;

    switch (choice) {
        case 1:
            add_player(players,score);
            start_snake_game();
        break;
        case 2:
            display_leaderboard(players);
        default:
            cout << "";
    }

    save_players_to_file(players, filename);
}

// int main() {
//     player_options(vector<Player>(), snake_obj.score);
//     return 0;
// }
