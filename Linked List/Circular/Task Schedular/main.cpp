#include "TaskList.h"

using namespace std;

int main()
{
    TaskList list;
    int choice, subChoice, id;
    string priority;
    Task *task;
    Task *target;

    do
    {
        cout << "\n-- Task Scheduler Menu --" << endl;
        cout << "1. Add New Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "   2.1 View next task" << endl;
        cout << "   2.2 View previous task" << endl;
        cout << "   2.3 View all tasks" << endl;
        cout << "3. Edit a Task" << endl;
        cout << "4. Delete a Task" << endl;
        cout << "5. View Tasks by Priority" << endl;
        cout << "6. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            task = new Task();
            task->add();
            list.insertAtTail(task);
            break;

        case 2:
            cout << "Enter sub-option (1 for next, 2 for previous, 3 for all): ";
            cin >> subChoice;
            cin.ignore();
            if (subChoice == 1)
            {
                list.printNext();
            }
            else if (subChoice == 2)
            {
                list.printPrevious();
            }
            else if (subChoice == 3)
            {
                list.printAll();
            }
            else
            {
                cout << "Invalid sub-option!" << endl;
            }
            break;

        case 3:
            cout << "Enter Task ID to edit: ";
            cin >> id;
            cin.ignore();
            target = list.searchTask(id);
            if (target != NULL)
            {
                cout << "Editing Task ID " << id << endl;
                target->add();
            }
            else
            {
                cout << "Task not found!" << endl;
            }
            break;

        case 4:
            cout << "Enter Task ID to delete: ";
            cin >> id;
            cin.ignore();
            target = list.searchTask(id);
            if (target != NULL)
            {
                list.removeTask(target);
                cout << "Task deleted." << endl;
            }
            else
            {
                cout << "Task not found!" << endl;
            }
            break;

        case 5:
            cout << "Enter priority to view (High/Medium/Low): ";
            getline(cin, priority);
            list.printByPriority(priority);
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
