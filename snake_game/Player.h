#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Player {
public:
    string user_name;
    int user_id;
    int score;

    explicit Player(string user_name = "", int user_id = 0, int score = 0);

    void save_to_file(ofstream &out) const;

    static bool load_from_file(ifstream &in, Player &player);
    void display_score() const;
};

void add_player(vector<Player> &players, int score);
void save_players_to_file(const vector<Player> &players, const string &filename);
void load_players_from_file(vector<Player> &players, const string &filename);
void display_leaderboard(const vector<Player> &players);

#endif
