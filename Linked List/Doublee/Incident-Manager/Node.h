#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
    int incident_id;
    string user_account;
    string threat_type;
    string severity;
    string detection_time;
    string status;
    string analyst_name;
    Node *next;
    Node *previous;

public:
    Node();
    Node(int);

    int get_incident_id();
    void set_incident_id(int);
    string get_user_account();
    void set_user_account(string);
    string get_threat_type();
    void set_threat_type(string);
    string get_severity();
    void set_severity(string);
    string get_detection_time();
    void set_detection_time(string);
    string get_status();
    void set_status(string);
    string get_analyst_name();
    void set_analyst_name(string);

    Node *get_next();
    void set_next(Node *);
    Node *get_previous();
    void set_previous(Node *);

    void display();
    void input();
};
