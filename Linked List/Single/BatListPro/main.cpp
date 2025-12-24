#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList team;
    int choice;

    do
    {
        cout << "\n********** -- Player Management Menu -- **********" << endl;
        cout << "1. Add Player" << endl;
        cout << "2. Display Player with Highest Total Runs" << endl;
        cout << "3. Search Opening Batsmen" << endl;
        cout << "4. Display Last Player in the List" << endl;
        cout << "5. Remove Last Player from the List" << endl;
        cout << "6. Remove 3rd Player from the List" << endl;
        cout << "7. Display All Players" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            Player player;
            player.input();

            if (player.get_batting_position() == "opening")
            {
                team.insert_at_head(player);
            }
            else if (player.get_batting_position() == "non-opening")
            {
                team.insert_at_tail(player);
            }
            else
            {
                cout << "Invalid Batting Position! Player not added.\n";
            }
            break;
        }
        case 2:
        {
            Player *highest = team.get_highest_scorer();
            if (highest)
            {
                cout << "\nPlayer with Highest Total Runs:\n";
                highest->display();
            }
            else
            {
                cout << "No player records found!\n";
            }
            break;
        }
        case 3:
        {
            team.search_opening_batsmen();
            break;
        }
        case 4:
        {
            Player *last = team.get_tail();
            if (last)
            {
                cout << "\nLast Player in the List:\n";
                last->display();
            }
            else
            {
                cout << "List is empty!\n";
            }
            break;
        }
        case 5:
        {
            team.remove_tail();
            cout << "\nLast player's record removed successfully." << endl;
            break;
        }
        case 6:
        {
            team.remove_at_position(3);
            break;
        }
        case 7:
        {
            cout << "\nAll Players:" << endl;
            team.print_all();
            break;
        }
        case 0:
            cout << "\nExiting Program..." << endl;
            break;

        default:
            cout << "\nInvalid choice !!! \nTry again." << endl;
        }

    } while (choice != 0);

    return 0;
}
