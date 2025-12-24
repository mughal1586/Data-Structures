#include "Student.h"
using namespace std;

class AttendanceRecord {
private:
    int capacity;
    int size;
    Student* students;

public:
/**************************************************** -- Constructor --  ****************************************************/
    AttendanceRecord(int);
/**************************************************** -- Getter/Setter --  ****************************************************/
    int get_capacity();
    void set_capacity(int);
    int get_size();
    void set_size(int);
/**************************************************** -- Others --  ****************************************************/
    void insert(int, string, float);
    void resize();
    void remove(int);
    int search(int);
    void shift(int);
    void display();
};
