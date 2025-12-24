#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int sap;
	string name;

public:
	/******************************************** -- Constructor -- ********************************************/

	Student();
	Student(int, string);

	/******************************************** -- Getter/Setter -- ********************************************/

	int get_sap();
	void set_sap(int);
	string get_name();
	void set_name(string);
};