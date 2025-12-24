#include "Player.h"

Player::Player()
{
    name = "";
    matches_played = -1;
    batting_position = "";
    total_runs = -1.0;
    average = -1.0;
    strike_rate = -1.0;
    no_of_fours = -1;
    no_of_sixes = -1;

    next = NULL;
}
Player::Player(Player &player)
{
    name = player.name;
    matches_played = player.matches_played;
    batting_position = player.batting_position;
    total_runs = player.total_runs;
    average = player.average;
    strike_rate = player.strike_rate;
    no_of_fours = player.no_of_fours;
    no_of_sixes = player.no_of_sixes;

    next = NULL;
}
string Player::get_name()
{
    return name;
}
void Player::set_name(string name)
{
    this->name = name;
}
int Player::get_matches_played()
{
    return matches_played;
}
void Player::set_matches_played(int matches_played)
{
    this->matches_played = matches_played;
}
string Player::get_batting_position()
{
    return batting_position;
}
void Player::set_batting_position(string batting_position)
{
    this->batting_position = batting_position;
}
float Player::get_total_runs()
{
    return total_runs;
}
void Player::set_total_runs(float total_runs)
{
    this->total_runs = total_runs;
}
float Player::get_average()
{
    return average;
}
void Player::set_average(float average)
{
    this->average = average;
}
float Player::get_strike_rate()
{
    return strike_rate;
}
void Player::set_strike_rate(float strike_rate)
{
    this->strike_rate = strike_rate;
}
int Player::get_no_of_fours()
{
    return no_of_fours;
}
void Player::set_no_of_fours(int no_of_fours)
{
    this->no_of_fours = no_of_fours;
}
int Player::get_no_of_sixes()
{
    return no_of_sixes;
}
void Player::set_no_of_sixes(int no_of_sixes)
{
    this->no_of_sixes = no_of_sixes;
}

Player *Player::get_next()
{
    return next;
}
void Player::set_next(Player *next)
{
    this->next = next;
}
void Player::input()
{
    cout << "Enter Player's Name: ";
    getline(cin, name);

    cout << "Enter Matches Played: ";
    cin >> matches_played;
    while (matches_played < 0)
    {
        cout << "Invalid Input !!! \nMatches must be greater than zero. \nTry again: ";
        cin >> matches_played;
    }

    cout << "Enter Batting Position (opening/non-opening): ";
    cin >> batting_position;
    while (batting_position != "opening" && batting_position != "non-opening")
    {
        cout << "Invalid Input !!! \nEnter 'opening' or 'non-opening': ";
        cin >> batting_position;
    }

    cout << "Enter Total Runs: ";
    cin >> total_runs;
    while (total_runs < 0)
    {
        cout << "Invalid Input !!! \nRuns must be greater than zero. \nTry again: ";
        cin >> total_runs;
    }

    cout << "Enter Batting Average: ";
    cin >> average;
    while (average < 0)
    {
        cout << "Invalid Input !!! \nAverage must be greater than zero. \nTry again: ";
        cin >> average;
    }

    cout << "Enter Strike Rate: ";
    cin >> strike_rate;
    while (strike_rate < 0)
    {
        cout << "Invalid Input !!! \nStrike Rate must be greater than zero. \nTry again: ";
        cin >> strike_rate;
    }

    cout << "Enter Total Number of Fours: ";
    cin >> no_of_fours;
    while (no_of_fours < 0)
    {
        cout << "Invalid Input !!! \nNumber of fours must be greater than zero. \nTry again: ";
        cin >> no_of_fours;
    }

    cout << "Enter Total Number of Sixes: ";
    cin >> no_of_sixes;
    while (no_of_sixes < 0)
    {
        cout << "Invalid Input !!! \nNumber of sixes must be greater than zero. \nTry again: ";
        cin >> no_of_sixes;
    }
}

void Player::display()
{
    cout << "----------------------------------------" << endl;
    cout << "Player's Name           : " << name << endl;
    cout << "Matches Played          : " << matches_played << endl;
    cout << "Batting Position        : " << batting_position << endl;
    cout << "Total Runs              : " << total_runs << endl;
    cout << "Batting Average         : " << average << endl;
    cout << "Strike Rate             : " << strike_rate << endl;
    cout << "Total Number of Fours   : " << no_of_fours << endl;
    cout << "Total Number of Sixes   : " << no_of_sixes << endl;
    cout << "----------------------------------------" << endl;
}
