#include "Student.h"

using namespace std;

class LinkedList
{
private:
    Student *head;
    Student *tail;

public:
    LinkedList();
    void insert_at_tail(Student);
    void insert_at_head(Student);
    void insert_at_target(int, Student);
    void remove(int);
    Student *search(int);
    bool is_empty();
    void print_all();

    void display_highest_attendance();
    void remove_at_position(int position);
};