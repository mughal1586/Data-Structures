#include "AttendanceRecord.h"
using namespace std;

/**************************************************** -- Implementation of Student--  ****************************************************/
/**************************************************** -- Constructor --  ****************************************************/
Student::Student() {
    id = 0;
    name = "";
    attendance = 0.0;
}

Student::Student(int id, string name, float attendance) {
    this->id = id;
    this->name = name;
    this->attendance = attendance;
}
/**************************************************** -- Getter/Setter --  ****************************************************/
int Student::get_id() {
    return id;
}

void Student::set_id(int id) {
    this->id = id;
}

string Student::get_name() {
    return name;
}

void Student::set_name(string name) {
    this->name = name;
}

float Student::get_attendance() {
    return attendance;
}

void Student::set_attendance(float attendance) {
    this->attendance = attendance;
}

/**************************************************** -- Implementation of AttendanceRecord --  ****************************************************/
/**************************************************** -- Constructor --  ****************************************************/
AttendanceRecord::AttendanceRecord(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    students = new Student[capacity];
}
/**************************************************** -- Getter/Setter --  ****************************************************/
int AttendanceRecord::get_capacity() {
    return capacity;
}

void AttendanceRecord::set_capacity(int capacity) {
    this->capacity = capacity;
}

int AttendanceRecord::get_size() {
    return size;
}

void AttendanceRecord::set_size(int size) {
    this->size = size;
}
/**************************************************** -- Others --  ****************************************************/
void AttendanceRecord::insert(int id, string name, float attendance) {
    if (size == capacity) {
        resize();
    }
    students[size] = Student(id, name, attendance);
    size++;
}

void AttendanceRecord::resize() {
    capacity =capacity * 2;
    Student* newstudents = new Student[capacity];
    for (int i = 0; i < size; i++) {
        newstudents[i].set_id(students[i].get_id());
        newstudents[i].set_name(students[i].get_name());
        newstudents[i].set_attendance(students[i].get_attendance());
    }
    delete[] students;
    students = newstudents;
}

void AttendanceRecord::remove(int id) {
int index = search(id);
if(index == -1){
    cout<<"Not Found !!!"<<endl;
}
else{
    students[index].set_id(-1);
    students[index].set_name("");
    students[index].set_attendance(-1.0);

    shift(index);
    size--;

}
}

void AttendanceRecord::shift(int index){
for(int i=index;i<size-1;i++){
    students[i].set_id(students[i+1].get_id());
    students[i].set_name(students[i+1].get_name());
    students[i].set_attendance(students[i+1].get_attendance());
}
}

int AttendanceRecord::search(int id){
for(int i=0;i<size;i++){
    if(students[i].get_id() == id){
        return i;
    }
}
return -1;
}

void AttendanceRecord::display() {
    cout << "\n----- Attendance Records -----"<<endl;
    for (int i = 0; i < size; i++) {
        cout << "ID: " << students[i].get_id()<< ", Name: " << students[i].get_name() << ", Attendance: " << students[i].get_attendance() << "%" << endl;
    }
    cout << endl;
}
