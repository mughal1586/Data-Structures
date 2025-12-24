#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    int id;
    string name;

public:
    /**************************************************** -- Constructor --  ****************************************************/
    Product();
    Product(int, string);
    /**************************************************** -- Getter/Setter --  ****************************************************/
    int get_id();
    void set_id(int);
    string get_name();
    void set_name(string);
};
