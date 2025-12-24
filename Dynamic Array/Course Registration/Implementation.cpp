#include "Course.h"

using namespace std;

/**************************************************** -- Implementation of Student -- ****************************************************/

/******************************************** -- Constructor -- ********************************************/

Student::Student()
{
	sap = -1;
	name = "";
}

Student::Student(int sap, string name)
{
	this->sap = sap;
	this->name = name;
}

/******************************************** -- Getter/Setter -- ********************************************/

int Student::get_sap()
{
	return sap;
}

void Student::set_sap(int sap)
{
	this->sap = sap;
}

string Student::get_name()
{
	return name;
}

void Student::set_name(string name)
{
	this->name = name;
}

/**************************************************** -- Implementation of Course -- ****************************************************/

/******************************************** -- Constructor -- ********************************************/

Course::Course(int course_id, string course_name)
{
	this->course_id = course_id;
	this->course_name = course_name;
	this->capacity = 10;
	this->currently_enrolled = 0;
	students = new Student[capacity];
}
Course::Course(int course_id, string course_name, int capacity)
{
	this->course_id = course_id;
	this->course_name = course_name;
	this->capacity = capacity;
	this->currently_enrolled = 0;
	students = new Student[capacity];
}

/******************************************** -- Getter/Setter -- ********************************************/

int Course::get_course_id()
{
	return course_id;
}

void Course::set_course_id(int course_id)
{
	this->course_id = course_id;
}

string Course::get_course_name()
{
	return course_name;
}

void Course::set_course_name(string course_name)
{
	this->course_name = course_name;
}

int Course::get_capacity()
{
	return capacity;
}

void Course::set_capacity(int capacity)
{
	this->capacity = capacity;
}

int Course::get_currently_enrolled()
{
	return currently_enrolled;
}

void Course::set_currently_enrolled(int currently_enrolled)
{
	this->currently_enrolled = currently_enrolled;
}

/******************************************** -- Others -- ********************************************/

void Course::enroll(int sap, string name)
{
	if (currently_enrolled == capacity)
	{
		resize();
	}
	else
	{
		students[currently_enrolled].set_sap(sap);
		students[currently_enrolled].set_name(name);

		currently_enrolled++;
	}
}

void Course::drop(int sap)
{

	int index = search(sap);
	if (index == -1)
	{
		cout << "\nStudent not found !!!" << endl;
	}
	else
	{
		students[index].set_sap(-1);
		students[index].set_name("");
		shift(index);
		currently_enrolled--;
	}
}

void Course::resize()
{
	capacity = capacity + 5;					  // 1.Increase capacity
	Student *newStudents = new Student[capacity]; // 2.Make a new array with large capacity
	for (int i = 0; i < currently_enrolled; i++)
	{
		newStudents[i].set_sap(students[i].get_sap()); // 3.Copy data from old arrays
		newStudents[i].set_name(students[i].get_name());
	}
	delete[] students;		// 4.Delete old array
	students = newStudents; // 5.Point new address
}

void Course::shift(int index)
{

	for (int i = index; i < currently_enrolled - 1; i++)
	{
		students[i].set_sap(students[i + 1].get_sap());
		students[i].set_name(students[i + 1].get_name());
	}
}

int Course::search(int sap)
{
	for (int i = 0; i < currently_enrolled; i++)
	{
		if (students[i].get_sap() == sap)
		{
			return i;
		}
	}
	return -1;
}