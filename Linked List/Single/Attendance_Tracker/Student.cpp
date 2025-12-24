#include "Student.h"

Student::Student()
{
    name = "";
    roll_no = -1;
    department = "";
    classes_held = -1;
    classes_attended = -1;
    attendance_percentage = -1.0;

    next = NULL;
}

Student::Student(Student &student)
{
    name = student.name;
    roll_no = student.roll_no;
    department = student.department;
    classes_held = student.classes_held;
    classes_attended = student.classes_attended;
    attendance_percentage = student.attendance_percentage;

    next = NULL;
}

string Student::get_name()
{
    return name;
}

void Student::set_name(string name)
{
    this->name = name;
}

int Student::get_roll_no()
{
    return roll_no;
}

void Student::set_roll_no(int roll_no)
{
    this->roll_no = roll_no;
}

string Student::get_department()
{
    return department;
}

void Student::set_department(string department)
{
    this->department = department;
}

int Student::get_classes_held()
{
    return classes_held;
}

void Student::set_classes_held(int classes_held)
{
    this->classes_held = classes_held;
}

int Student::get_classes_attended()
{
    return classes_attended;
}

void Student::set_classes_attended(int classes_attended)
{
    this->classes_attended = classes_attended;
}

float Student::get_attendance_percentage()
{
    return attendance_percentage;
}

void Student::set_attendance_percentage(float attendance_percentage)
{
    this->attendance_percentage = attendance_percentage;
}

Student *Student::get_next()
{
    return next;
}

void Student::set_next(Student *next)
{
    this->next = next;
}

void Student::input()
{
    cout << "Enter Student's Name: ";
    getline(cin, name);

    cout << "Enter Roll Number: ";
    cin >> roll_no;
    while (roll_no <= 0)
    {
        cout << "Invalid Input !!! \nRoll number must be greater than zero. \nTry again: ";
        cin >> roll_no;
    }

    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, department);

    cout << "Enter Number of Classes Held: ";
    cin >> classes_held;
    while (classes_held <= 0)
    {
        cout << "Invalid Input !!! \nClasses held must be greater than zero. \nTry again: ";
        cin >> classes_held;
    }

    cout << "Enter Number of Classes Attended: ";
    cin >> classes_attended;
    while (classes_attended < 0 || classes_attended > classes_held)
    {
        cout << "Invalid Input !!! \nClasses attended must be between 0 and " << classes_held << ". \nTry again: ";
        cin >> classes_attended;
    }

    attendance_percentage = ((float)classes_attended / classes_held) * 100;
}

void Student::display()
{
    cout << "----------------------------------------" << endl;
    cout << "Student's Name           : " << name << endl;
    cout << "Roll Number              : " << roll_no << endl;
    cout << "Department               : " << department << endl;
    cout << "Classes Held             : " << classes_held << endl;
    cout << "Classes Attended         : " << classes_attended << endl;
    cout << "Attendance Percentage    : " << attendance_percentage << "%" << endl;
    cout << "----------------------------------------" << endl;
}
