#include<iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    float attendance;

public:
/**************************************************** -- Constructor --  ****************************************************/
    Student();
    Student(int id, string name, float attendance);
/**************************************************** -- Getter/Setter --  ****************************************************/
    int get_id();
    void set_id(int);
    string get_name();
    void set_name(string);
    float get_attendance();
    void set_attendance(float);
};
