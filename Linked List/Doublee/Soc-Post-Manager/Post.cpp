#include "Post.h"

using namespace std;

Post::Post()
{
    message = "";
    share_with = 1;
    date = "";
    previous = NULL;
    next = NULL;
}

Post::Post(Post &post)
{
    message = post.message;
    share_with = post.share_with;
    date = post.date;
    previous = post.previous;
    next = post.next;
}

string Post::get_message()
{
    return message;
}

void Post::set_message(string msg)
{
    message = msg;
}

int Post::get_share_with()
{
    return share_with;
}

void Post::set_share_with(int privacy)
{
    if (privacy >= 1 && privacy <= 3)
    {
        share_with = privacy;
    }
    else
    {
        share_with = 1;
    }
}

string Post::get_date()
{
    return date;
}

void Post::set_date(string dt)
{
    date = dt;
}

Post *Post::get_previous()
{
    return previous;
}

void Post::set_previous(Post *prev)
{
    previous = prev;
}

Post *Post::get_next()
{
    return next;
}

void Post::set_next(Post *nxt)
{
    next = nxt;
}

void Post::insert()
{
    cout << "\n--- Create New Post ---\n";

    cin.ignore();

    cout << "Enter message: ";
    getline(cin, message);

    cout << "\nSelect Privacy:" << endl;
    cout << "1. Public" << endl;
    cout << "2. Friends" << endl;
    cout << "3. Private" << endl;
    cout << "Enter choice (1-3): ";
    cin >> share_with;

    while (share_with < 1 || share_with > 3)
    {
        cout << "Invalid choice! Enter 1, 2, or 3: ";
        cin >> share_with;
    }

    cout << "Enter date (e.g., Oct 31, 2025): ";
    cin.ignore();
    getline(cin, date);

    cout << "\nPost created successfully!" << endl;
}

void Post::display()
{
    cout << "\n-----------------------------------" << endl;
    cout << "Message: " << message << endl;
    cout << "Privacy: ";
    if (share_with == 1)
    {
        cout << "Public" << endl;
    }
    else if (share_with == 2)
    {
        cout << "Friends" << endl;
    }
    else if (share_with == 3)
    {
        cout << "Private" << endl;
    }
    cout << "Date: " << date << endl;
    cout << "\n-----------------------------------" << endl;
}
