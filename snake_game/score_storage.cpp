#include <iostream>
#include <fstream>

using namespace std;

class Storage {
public:
    int score;
    string player_id;

    void save_to_file(ofstream &out) const {
        out << score;
    }

    static bool load_from_file(ifstream &in, ) {
        if (!getline(in, )) return false;

        return true;
    }
};