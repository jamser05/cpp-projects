#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <limits>

using namespace std;

typedef vector<vector<char>> vvc;
typedef set<int> si;

const int COLUMNS = 3;
const int ROWS = 3;

enum Direction {
    DOWN,
    RIGHT,
    DOWN_RIGHT,
    DOWN_LEFT
};

class TicTacToe {
    public:

    vvc board;
    si positions_in_use;

    string player1;
    string player2;

    bool game_in_progress = true;

    TicTacToe() {
        board.resize(ROWS, vector<char>(COLUMNS));
    }

    void make_board() {
        for (int row = 0; row < ROWS; row++) {
            for (int column = 0; column < COLUMNS; column++) {
                board[row][column] = ' ';
            }
        }
    }

    string get_player1_name() {
        cout << "Enter player 1's name: ";
        cin >> player1;
        return player1;
    }

    string get_player2_name() {
        cout << "Enter player 2's name: ";
        cin >> player2;
        return player2;
    }

    void get_player_placement_position(char player_symbol) {
        int symbol_position;

        do {
            cout << "Place piece at: ";

            while (!(cin >> symbol_position)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid position.";
            }

            if (positions_in_use.find(symbol_position) != positions_in_use.end()) {
                cout << "Position " << symbol_position << " is in use.\nTry again.\n";
            }

        }  while (positions_in_use.find(symbol_position) != positions_in_use.end());
        positions_in_use.insert(symbol_position);

        switch (symbol_position) {
            case (1):
                board[0][0] = player_symbol;
                break;
            case (2):
                board[0][1] = player_symbol;
                break;
            case (3):
                board[0][2] = player_symbol;
                break;
            case (4):
                board[1][0] = player_symbol;
                break;
            case (5):
                board[1][1] = player_symbol;
                break;
            case (6):
                board[1][2] = player_symbol;
                break;
            case (7):
                board[2][0] = player_symbol;
                break;
            case (8):
                board[2][1] = player_symbol;
                break;
            case (9):
                board[2][2] = player_symbol;
                break;
            default:
                break;
        }
    }

    bool check_for_winner(const char player, vvc board, const int sr, const int sc, const int count, const Direction direction) {
        if (sr < 0 || sr >= board.size() || sc < 0 || sc >= board[0].size()) {
            return count >= 3;
        }

        if (board[sr][sc] != player) {
            return count >= 3;
        }

        switch (direction) {
            case DOWN:
                return check_for_winner(player, board, sr + 1, sc, count + 1, direction);
            case RIGHT:
                return check_for_winner(player, board, sr, sc + 1, count + 1, direction);
            case DOWN_RIGHT:
                return check_for_winner(player, board, sr + 1, sc + 1, count + 1, direction);
            case DOWN_LEFT:
                return check_for_winner(player, board, sr + 1, sc - 1, count + 1, direction);
            default:
                return false;
        }
    }

    bool draw(int sr = 0, int sc = 0, set<pair<int,int>> visit = set<pair<int, int>>(), int count = 0) {
        if (sr < 0 || sr >= board.size() || sc < 0 || sc >= board[0].size()) {
            return count >= 9;
        }

        if (board[sr][sc] == ' ') {
            return count >= 9;
        }

        pair pos = {sr, sc};

        if (visit.find(pos) == visit.end()) {
            visit.insert(pos);
            count += 1;
        } else {
            return count >= 9;
        }

        return draw(sr + 1, sc, visit, count) ||
        draw(sr - 1, sc, visit, count) ||
        draw(sr, sc + 1, visit, count) ||
        draw(sr, sc - 1, visit, count);
    }

    bool winner_found(const char current_player_symbol) {
        for (int i = 0; i < ROWS; i++) {
            if (check_for_winner(current_player_symbol, board, 0, i, 0, DOWN)) {
                return true;
            }

            if (check_for_winner(current_player_symbol, board, i, 0, 0, RIGHT)) {
                return true;
            }
        }

        if (check_for_winner(current_player_symbol, board, 0, 0, 0, DOWN_RIGHT)) {
            return true;
        }

        if (check_for_winner(current_player_symbol, board, 0, COLUMNS - 1, 0, DOWN_LEFT)) {
            return true;
        }

        return false;
    }

    pair<string, char> choose_player(string player1_name, string player2_name, int moves_made) {
        char player1 = 'X'; char player2 = 'O';

        char current_player_symbol;
        string current_player_name;

        if (moves_made % 2 == 0) {
            current_player_symbol = player1;
            current_player_name = std::move(player1_name);
        } else {
            current_player_symbol = player2;
            current_player_name = std::move(player2_name);
        }

        get_player_placement_position(current_player_symbol);

        return  pair(current_player_name, current_player_symbol);
    }

    void reset_game() {
        board.clear();
        positions_in_use.clear();
    }

    void preview_board() {
        int position = 1;

        cout << "Tic-Tac-Toe Board  Positions Board:\n";
        cout << "===========        ===========\n";

        for (int row = 0; row < ROWS; row++) {
            for (int column = 0; column < COLUMNS; column++) {
                cout << " " << board[row][column] << " ";

                if (column < COLUMNS - 1) {
                    cout << "|";
                }
            }

            cout << "        ";

            for (int column = 0; column < COLUMNS; column++) {
                cout << "|" << position << "|";
                position += 1;
            }

            cout << "\n";

            if (row < ROWS -1) {
                cout << "-----------        -----------\n";
            }
        }
    }


    void welcome_player() {
        cout << "Welcome to Tic-Tac-Toe!\n";
        preview_board();
    }
} tic_tac_toe;



int start_game() {
    tic_tac_toe.welcome_player();

    string player1_name = tic_tac_toe.get_player1_name();
    string player2_name = tic_tac_toe.get_player2_name();

    int moves_made = 0;

    tic_tac_toe.make_board();

    while (true) {
        tic_tac_toe.preview_board();

        if (tic_tac_toe.draw()) {
            cout << "Draw";
            break;
        }

        pair player = tic_tac_toe.choose_player( player1_name, player2_name, moves_made);

        char current_player_symbol = player.second;
        string current_player_name = player.first;

        if (tic_tac_toe.winner_found(current_player_symbol)) {
            tic_tac_toe.preview_board();
            cout << current_player_name << " " << "has won!" << "\n";
            tic_tac_toe.reset_game();
            break;
        }

        moves_made++;
    }

    return 0;
}

int main() {
    start_game();
    return 0;
}