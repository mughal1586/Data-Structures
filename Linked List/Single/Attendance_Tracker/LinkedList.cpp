#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}
void LinkedList::insert_at_tail(Student student)
{
    if (is_empty())
    {
        Student *temp = new Student(student);
        head = temp;
        tail = temp;
    }
    else
    {
        Student *temp = new Student(student);
        tail->set_next(temp);
        tail = temp;
    }
}
void LinkedList::insert_at_head(Student student)
{
    if (is_empty())
    {
        Student *temp = new Student(student);
        head = temp;
        tail = temp;
    }
    else
    {
        Student *temp = new Student(student);
        temp->set_next(head);
        head = temp;
    }
}
void LinkedList::insert_at_target(int find_by_roll_no, Student student)
{
    Student *target_student = search(find_by_roll_no);
    if (target_student == NULL)
    {
        cout << "\nStudent not Found !!!" << endl;
        return;
    }
    else
    {
        if (target_student == tail)
        {
            insert_at_tail(student);
            return;
        }
        else
        {
            Student *temp = new Student(student);
            temp->set_next(target_student->get_next());
            target_student->set_next(temp);
        }
    }
    return;
}
void LinkedList::remove(int find_by_roll_no)
{
    Student *target_student = head;
    Student *previous_student = NULL;
    while (target_student != NULL)
    {
        if (target_student->get_roll_no() == find_by_roll_no)
        {
            break;
        }
        else
        {
            previous_student = target_student;
            target_student = target_student->get_next();
        }
    }
    if (target_student == NULL)
    {
        cout << "\nStudent not Found !!!" << endl;
        return;
    }
    else if (target_student == head)
    {
        head = target_student->get_next();
        target_student->set_next(NULL);
        delete target_student;
    }
    else if (target_student == tail)
    {
        previous_student = NULL;
        tail = previous_student;
        delete target_student;
    }
    else
    {
        previous_student->set_next(target_student->get_next());
        target_student->set_next(NULL);
        delete target_student;
    }
}
Student *LinkedList::search(int find_by_roll_no)
{
    Student *temp = head;
    while (temp != NULL)
    {
        if (temp->get_roll_no() == find_by_roll_no)
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
    Student *temp = head;
    while (temp != NULL)
    {
        temp->display();
        temp = temp->get_next();
    }
}

void LinkedList::display_highest_attendance()
{
    if (is_empty())
    {
        cout << "\nList is empty." << endl;
        return;
    }

    Student *temp = head;
    Student *highest = head;

    while (temp != NULL)
    {
        if (temp->get_attendance_percentage() > highest->get_attendance_percentage())
        {
            highest = temp;
        }
        temp = temp->get_next();
    }

    cout << "\nStudent with Highest Attendance:" << endl;
    highest->display();
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

    Student *temp = head;
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

    int target_student = temp->get_roll_no();
    remove(target_student);
}
