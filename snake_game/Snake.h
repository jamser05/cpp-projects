#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

using namespace std;

typedef vector<pair<int, int>> snake_rep;
typedef pair<int, int> food_rep;
typedef vector<vector<char>> board_rep;
typedef char symbol;

class Snake {
public:
    snake_rep snake; 
    symbol snake_symbol = '@';
    food_rep food; 
    symbol food_symbol = 'O';
    symbol border_symbol = '#'; 
    symbol empty_space = ' ';
    board_rep board;

    int score = 0;

    Snake();
    static int generate_random_position(int lower_bound, int upper_bound);
    bool out_of_bounds();
    bool snake_hit_itself();
    void get_snake_location();
    bool is_food_eaten();
    void eat_food(char direction);
    void get_food_location();
    void make_board();
    void update_snake_position(char direction);
    void preview_board();
};

#endif
