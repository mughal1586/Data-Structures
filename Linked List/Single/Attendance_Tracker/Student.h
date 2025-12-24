#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int roll_no;
    string department;
    int classes_held;
    int classes_attended;
    float attendance_percentage;

    Student *next;

public:
    Student();
    Student(Student &);
    string get_name();
    void set_name(string);
    int get_roll_no();
    void set_roll_no(int);
    string get_department();
    void set_department(string);
    int get_classes_held();
    void set_classes_held(int);
    int get_classes_attended();
    void set_classes_attended(int);
    float get_attendance_percentage();
    void set_attendance_percentage(float);

    void input();
    void display();

    Student *get_next();
    void set_next(Student *);
};