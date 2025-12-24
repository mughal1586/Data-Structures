#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}
void LinkedList::insert_at_tail(Player player)
{
    if (is_empty())
    {
        Player *temp = new Player(player);
        head = temp;
        tail = temp;
    }
    else
    {
        Player *temp = new Player(player);
        tail->set_next(temp);
        tail = temp;
    }
}
void LinkedList::insert_at_head(Player player)
{
    if (is_empty())
    {
        Player *temp = new Player(player);
        temp = head;
        temp = tail;
    }
    else
    {
        Player *temp = new Player(player);
        temp->set_next(head);
        head = temp;
    }
}
void LinkedList::insert_at_target(string name, Player player)
{
    Player *target = search(name);
    if (target == NULL)
    {
        cout << "\nNot Found !!!" << endl;
        return;
    }
    else
    {
        if (target == tail)
        {
            insert_at_tail(player);
        }
        else
        {
            Player *temp = new Player(player);
            temp->set_next(target->get_next());
            target->set_next(temp);
        }
    }
}
void LinkedList::remove(string name)
{
    Player *target_player = head;
    Player *previous_player = NULL;
    while (target_player != NULL)
    {
        if (target_player->get_name() == name)
        {
            break;
        }
        else
        {
            previous_player = target_player;
            target_player = target_player->get_next();
        }
    }
    if (target_player == NULL)
    {
        cout << "\nNot Found !!!" << endl;
        return;
    }
    else if (target_player == head)
    {
        head = target_player->get_next();
        target_player->set_next(NULL);
        delete target_player;
    }
    else if (target_player == tail)
    {
        previous_player = NULL;
        tail = previous_player;
        delete target_player;
    }
    else
    {
        previous_player->set_next(target_player->get_next());
        target_player->set_next(NULL);
        delete target_player;
    }
}
Player *LinkedList::search(string name)
{
    Player *temp = head;
    while (temp != NULL)
    {
        if (temp->get_name() == name)
        {
            return temp;
        }
        else
        {
            temp = temp->get_next();
        }
    }
    return NULL;
}
bool LinkedList::is_empty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
void LinkedList::print_all()
{
    Player *temp = head;
    while (temp != NULL)
    {
        temp->display();
        temp = temp->get_next();
    }
}

void LinkedList::remove_tail()
{
    if (is_empty())
    {
        cout << "\nList is empty. Nothing to remove." << endl;
        return;
    }

    string tail_name = tail->get_name();
    remove(tail_name);
}
void LinkedList::remove_at_position(int position)
{
    if (is_empty())
    {
        cout << "\nList is empty. Nothing to remove." << endl;
        return;
    }

    if (position <= 0)
    {
        cout << "\nInvalid position !!! \nPosition must be greater than 0." << endl;
        return;
    }

    Player *temp = head;
    int index = 1;

    while (temp != NULL && index < position)
    {
        temp = temp->get_next();
        index++;
    }

    if (temp == NULL)
    {
        cout << "Invalid position. No player exists at position " << position << ".\n";
        return;
    }

    string target_name = temp->get_name();
    remove(target_name);
}

Player *LinkedList::get_tail()
{
    return tail;
}
Player *LinkedList::get_highest_scorer()
{
    if (is_empty())
        return NULL;

    Player *temp = head;
    Player *highest = head;

    while (temp != NULL)
    {
        if (temp->get_total_runs() > highest->get_total_runs())
        {
            highest = temp;
        }
        temp = temp->get_next();
    }

    return highest;
}
void LinkedList::search_opening_batsmen()
{
    if (is_empty())
    {
        cout << "\nNo players found." << endl;
        return;
    }

    Player *temp = head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->get_batting_position() == "opening")
        {
            temp->display();
            found = true;
        }
        temp = temp->get_next();
    }

    if (!found)
    {
        cout << "\nNo opening batsmen found." << endl;
    }
}
