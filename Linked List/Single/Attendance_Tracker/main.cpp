#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList record;
    int choice;

    do
    {
        cout << "\n********** -- Attendance Management Menu -- **********" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Student with Highest Attendance Percentage" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Delete 3rd Student from the List" << endl;
        cout << "5. Display All Students" << endl;
        cout << "0. Exit" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            Student student;
            student.input();

            if (student.get_attendance_percentage() > 80.0)
            {
                record.insert_at_head(student);
            }
            else
            {
                record.insert_at_tail(student);
            }
            break;
        }
        case 2:
        {
            record.display_highest_attendance();
        }
        case 3:
        {
            int roll_no;
            cout << "Enter Roll Number to search: ";
            cin >> roll_no;

            Student *found = record.search(roll_no);
            if (found)
            {
                cout << "\nStudent Found:\n";
                found->display();
            }
            else
            {
                cout << "Student not found!\n";
            }
            break;
        }
        case 4:
        {
            record.remove_at_position(3);
            break;
        }
        case 5:
        {
            cout << "\nAll Students:" << endl;
            record.print_all();
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
