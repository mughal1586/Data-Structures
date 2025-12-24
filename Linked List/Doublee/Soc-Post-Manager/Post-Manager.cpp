#include "Post-Manager.h"

using namespace std;

PostManager::PostManager()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

bool PostManager::is_empty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

void PostManager::new_post()
{
    Post *temp = new Post();
    temp->insert();

    if (is_empty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->set_next(temp);
        temp->set_previous(tail);
        tail = temp;
    }

    count++;
}

void PostManager::view_posts()
{
    if (is_empty())
    {
        cout << "\nNo posts available!" << endl;
        return;
    }

    int choice;
    cout << "\n--- View Posts ---" << endl;
    cout << "1. View newer post" << endl;
    cout << "2. View by privacy" << endl;
    cout << "3. View all" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        view_newer_post();
    }
    else if (choice == 2)
    {
        view_by_privacy();
    }
    else if (choice == 3)
    {
        view_all();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}

void PostManager::view_newer_post()
{
    if (is_empty())
    {
        cout << "\nNo posts available!" << endl;
        return;
    }

    navigate_posts(tail);
}

void PostManager::view_by_privacy()
{
    if (is_empty())
    {
        cout << "\nNo posts available!" << endl;
        return;
    }

    int privacy;
    cout << "\nSelect Privacy to view:" << endl;
    cout << "1. Public" << endl;
    cout << "2. Friends" << endl;
    cout << "3. Private" << endl;
    cout << "Enter choice (1-3): ";
    cin >> privacy;

    Post *current = tail;
    bool found = false;

    while (current != NULL)
    {
        if (current->get_share_with() == privacy)
        {
            found = true;
            current->display();

            char option;
            cout << "\n[N]ext | [P]revious | [E]dit | [D]elete | [Q]uit: ";
            cin >> option;

            if (option == 'N' || option == 'n')
            {
                Post *temp = current->get_previous();
                while (temp != NULL && temp->get_share_with() != privacy)
                {
                    temp = temp->get_previous();
                }
                if (temp != NULL)
                {
                    current = temp;
                }
                else
                {
                    cout << "\nNo more posts with this privacy!" << endl;
                }
            }
            else if (option == 'P' || option == 'p')
            {
                Post *temp = current->get_next();
                while (temp != NULL && temp->get_share_with() != privacy)
                {
                    temp = temp->get_next();
                }
                if (temp != NULL)
                {
                    current = temp;
                }
                else
                {
                    cout << "\nNo previous posts with this privacy!" << endl;
                }
            }
            else if (option == 'E' || option == 'e')
            {
                edit_post(current);
            }
            else if (option == 'D' || option == 'd')
            {
                Post *temp = current->get_previous();
                while (temp != NULL && temp->get_share_with() != privacy)
                {
                    temp = temp->get_previous();
                }
                delete_post(current);
                if (temp == NULL)
                {
                    break;
                }
                current = temp;
            }
            else if (option == 'Q' || option == 'q')
            {
                break;
            }
        }
        else
        {
            current = current->get_previous();
        }
    }

    if (!found)
    {
        cout << "\nNo posts found with this privacy setting!" << endl;
    }
}

void PostManager::view_all()
{
    if (is_empty())
    {
        cout << "\nNo posts available!" << endl;
        return;
    }

    navigate_posts(tail);
}

void PostManager::navigate_posts(Post *current)
{
    if (current == NULL)
    {
        cout << "\nNo post to display!" << endl;
        return;
    }

    while (current != NULL)
    {
        current->display();

        char option;
        cout << "\n[N]ext | [P]revious | [E]dit | [D]elete | [Q]uit: ";
        cin >> option;

        if (option == 'N' || option == 'n')
        {
            if (current->get_previous() != NULL)
            {
                current = current->get_previous();
            }
            else
            {
                cout << "\nThis is the oldest post!" << endl;
            }
        }
        else if (option == 'P' || option == 'p')
        {
            if (current->get_next() != NULL)
            {
                current = current->get_next();
            }
            else
            {
                cout << "\nThis is the newest post!" << endl;
            }
        }
        else if (option == 'E' || option == 'e')
        {
            edit_post(current);
        }
        else if (option == 'D' || option == 'd')
        {
            Post *temp = current->get_previous();
            delete_post(current);
            current = temp;
            if (current == NULL)
            {
                cout << "\nNo more posts!" << endl;
                break;
            }
        }
        else if (option == 'Q' || option == 'q')
        {
            break;
        }
        else
        {
            cout << "\nInvalid option!" << endl;
        }
    }
}

void PostManager::edit_post(Post *post)
{
    if (post == NULL)
    {
        return;
    }

    int choice;
    cout << "\n--- Edit Post ---" << endl;
    cout << "1. Edit message" << endl;
    cout << "2. Edit privacy" << endl;
    cout << "3. Edit both" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1 || choice == 3)
    {
        string new_message;
        cout << "Enter new message: ";
        getline(cin, new_message);
        post->set_message(new_message);
    }

    if (choice == 2 || choice == 3)
    {
        int new_privacy;
        cout << "\nSelect new Privacy:" << endl;
        cout << "1. Public" << endl;
        cout << "2. Friends" << endl;
        cout << "3. Private" << endl;
        cout << "Enter choice (1-3): ";
        cin >> new_privacy;
        post->set_share_with(new_privacy);
    }

    cout << "\nPost updated successfully!" << endl;
}

void PostManager::delete_post(Post *&post)
{
    if (post == NULL)
    {
        cout << "\nNot Found!" << endl;
        return;
    }

    char confirm;
    cout << "\nAre you sure you want to delete this post? (Y/N): ";
    cin >> confirm;

    if (confirm != 'Y' && confirm != 'y')
    {
        cout << "Delete cancelled." << endl;
        return;
    }

    Post *prev = post->get_previous();
    Post *next = post->get_next();

    if (post == head)
    {
        head = head->get_next();
        if (head != NULL)
        {
            head->set_previous(NULL);
        }
        post->set_next(NULL);
        delete post;
    }
    else if (post == tail)
    {
        tail = tail->get_previous();
        if (tail != NULL)
        {
            tail->set_next(NULL);
        }
        post->set_previous(NULL);
        delete post;
    }
    else
    {
        prev->set_next(next);
        next->set_previous(prev);
        post->set_next(NULL);
        post->set_previous(NULL);
        delete post;
    }

    post = NULL;
    count--;

    cout << "Post deleted successfully!" << endl;
}
