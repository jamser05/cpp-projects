#include "Player.h"

#include <iomanip>
#include <random>
#include <bits/random.h>

Player::Player(string user_name, int user_id, int score) 
    : user_name(move(user_name)), user_id(user_id), score(score) {}

void Player::save_to_file(ofstream &out) const {
    out << user_name << '\n' << user_id << '\n' << score << '\n';
}

void Player::display_score() const {
        cout << setw(15) << left << user_name << setw(10) << right << score;
}

bool Player::load_from_file(ifstream &in, Player &player) {
    if (!(getline(in, player.user_name))) {
        return false;
    }
    if (!(in >> player.user_id)) {
        return false;
    }
    if (!(in >> player.score)) {
        return false;
    }
    in.ignore();
    return true;
}

void add_player(vector<Player> &players, int score) {
    string user_name;

    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, user_name);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1000, 9999);

    int user_id = dist(gen);

    players.emplace_back(user_name, user_id, score);
}



void save_players_to_file(const vector<Player> &players, const string &filename) {
    ofstream out(filename, ios::trunc);

    if (!out.is_open()) {
        cout << "Failed to open the file for writing!\n";
        return;
    }

    for (const auto &player : players) {
        player.save_to_file(out);
    }
}

void load_players_from_file(vector<Player> &players, const string &filename) {
    ifstream in(filename);

    if (!in.is_open()) {
        cout << "No previous records found. Starting with an empty list.\n";
        return;
    }

    Player player;
    while (Player::load_from_file(in, player)) {
        players.push_back(player);
    }
}

void display_leaderboard(const vector<Player> &players) {
    if (players.empty()) {
        cout << "No players found.\n";
        cout << "No players found.\n";
        return;
    }

    cout << setw(15) << left << "Username" << setw(10) << right << "Score" << "\n";
    cout << string(15, '-') << " " << string(10, '-') << "\n";

    for (const auto &player : players) {
        player.display_score();
        cout << "\n";
    }
}