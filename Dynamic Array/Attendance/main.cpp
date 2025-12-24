#include "AttendanceRecord.h"
using namespace std;

int main() {
    AttendanceRecord record(5);

    record.insert(101, "Ali", 95.5);
    record.insert(102, "Babar", 88.0);
    record.insert(103, "Umar", 90.2);
    record.insert(104, "Arslan", 82.3);
    record.insert(105, "Nouman", 96.7);

    record.insert(106, "Naeem", 84.6);
    record.insert(107, "Zawar", 91.4);
    record.insert(108, "Hannan", 87.8);

    cout << "\nAfter inserting 8 students:";
    record.display();

    record.remove(103);
    record.remove(106);

    cout << "\nAfter removing 2 withdrawn students:";
    record.display();

    record.insert(109, "Issa", 92.1);
    record.insert(110, "Jamshaid", 85.9);
    record.insert(111, "Khalid", 89.3);

    cout << "\nAfter inserting 3 new students:";
    record.display();

    return 0;
}
