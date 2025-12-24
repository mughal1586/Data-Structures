#include "Player.h"

using namespace std;

class LinkedList
{
private:
    Player *head;
    Player *tail;

public:
    LinkedList();
    void insert_at_tail(Player);
    void insert_at_head(Player);
    void insert_at_target(string, Player);
    void remove(string);
    Player *search(string);
    bool is_empty();
    void print_all();

    void remove_tail();
    void remove_at_position(int position);
    Player *get_tail();
    Player *get_highest_scorer();
    void search_opening_batsmen();
};