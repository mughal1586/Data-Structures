#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int matches_played;
    string batting_position;
    float total_runs;
    float average;
    float strike_rate;
    int no_of_fours;
    int no_of_sixes;

    Player *next;

public:
    Player();
    Player(Player &);
    string get_name();
    void set_name(string);
    int get_matches_played();
    void set_matches_played(int);
    string get_batting_position();
    void set_batting_position(string);
    float get_total_runs();
    void set_total_runs(float);
    float get_average();
    void set_average(float);
    float get_strike_rate();
    void set_strike_rate(float);
    int get_no_of_fours();
    void set_no_of_fours(int);
    int get_no_of_sixes();
    void set_no_of_sixes(int);
    void input();
    void display();

    Player *get_next();
    void set_next(Player *);
};
