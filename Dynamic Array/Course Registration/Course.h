#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

class Course
{
private:
	int course_id;
	string course_name;
	int capacity;
	int currently_enrolled;
	Student *students;

public:
	/******************************************** -- Constructor -- ********************************************/
	Course(int, string);
	Course(int, string, int);

	/******************************************** -- Getter/Setter -- ********************************************/

	int get_course_id();
	void set_course_id(int);
	string get_course_name();
	void set_course_name(string);
	int get_capacity();
	void set_capacity(int);
	int get_currently_enrolled();
	void set_currently_enrolled(int);

	/******************************************** -- Others -- ********************************************/

	void enroll(int, string);
	void drop(int);
	void resize();
	void shift(int);
	int search(int);
};