#include<iostream>
#include<string>

using namespace std;

class Node{
private:
	int data;

public:
	Node();
	Node(int);

	int get_data();
	void set_data(int);
};
