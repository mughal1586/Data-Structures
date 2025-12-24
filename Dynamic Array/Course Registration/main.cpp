#include "Course.h"

using namespace std;

int main()
{
	int courseID, capacity;
	string courseName;
	cout << "--------------------------------" << endl;
	cout << "\t-: Course Details :-" << endl;
	cout << "Enter Course ID: ";
	cin >> courseID;
	cin.ignore();
	cout << "Enter Course Name: ";
	getline(cin, courseName);
	cout << "Enter Capacity: ";
	cin >> capacity;
	cout << "\n--------------------------------" << endl;

	Course course(courseID, courseName, capacity);

	int choice;
	do
	{
		cout << "\n--------------------------------" << endl;
		cout << "\nMenu:\n";
		cout << "1. Enroll Student\n";
		cout << "2. Drop Student\n";
		cout << "3. Search Student by SAP\n";
		cout << "4. Display Course Info\n";
		cout << "5. Exit\n";
		cout << "\n--------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int sap;
			string name;
			cout << "Enter Student SAP: ";
			cin >> sap;
			cin.ignore();
			cout << "Enter Student Name: ";
			getline(cin, name);
			course.enroll(sap, name);
			break;
		}
		case 2:
		{
			int sap;
			cout << "Enter Student SAP: ";
			cin >> sap;
			course.drop(sap);
			break;
		}
		case 3:
		{
			int sap;
			cout << "Enter SAP to search: ";
			cin >> sap;
			int idx = course.search(sap);
			if (idx != -1)
				cout << "Student found at index: " << idx << endl;
			else
				cout << "Student not found!\n";
			break;
		}
		case 4:
		{
			cout << "Course ID: " << course.get_course_id() << endl;
			cout << "Course Name: " << course.get_course_name() << endl;
			cout << "Capacity: " << course.get_capacity() << endl;
			cout << "Currently Enrolled: " << course.get_currently_enrolled() << endl;
			break;
		}
		case 5:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice!\n";
		}
	} while (choice != 5);

	return 0;
}
