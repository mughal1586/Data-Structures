#include "Post-Manager.h"

using namespace std;

int main()
{
    PostManager system;
    int choice;

    do
    {
        cout << "1. New Post" << endl;
        cout << "2. View Posts" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            system.new_post();
            break;
        case 2:
            system.view_posts();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
