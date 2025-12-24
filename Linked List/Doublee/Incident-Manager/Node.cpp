#include "Node.h"

using namespace std;

Node::Node()
{
    incident_id = 0;
    user_account = "";
    threat_type = "";
    severity = "";
    detection_time = "";
    status = "";
    analyst_name = "";
    next = NULL;
    previous = NULL;
}

Node::Node(int id)
{
    incident_id = id;
    next = NULL;
    previous = NULL;
}

int Node::get_incident_id()
{
    return incident_id;
}

void Node::set_incident_id(int id)
{
    incident_id = id;
}

string Node::get_user_account()
{
    return user_account;
}

void Node::set_user_account(string user_account)
{
    user_account = user_account;
}

string Node::get_threat_type()
{
    return threat_type;
}

void Node::set_threat_type(string threat_type)
{
    threat_type = threat_type;
}

string Node::get_severity()
{
    return severity;
}

void Node::set_severity(string severity)
{
    severity = severity;
}

string Node::get_detection_time()
{
    return detection_time;
}

void Node::set_detection_time(string detection_time)
{
    detection_time = detection_time;
}

string Node::get_status()
{
    return status;
}

void Node::set_status(string status)
{
    status = status;
}

string Node::get_analyst_name()
{
    return analyst_name;
}

void Node::set_analyst_name(string analyst_name)
{
    analyst_name = analyst_name;
}

Node *Node::get_next()
{
    return next;
}

void Node::set_next(Node *next)
{
    next = next;
}

Node *Node::get_previous()
{
    return previous;
}

void Node::set_previous(Node *previous)
{
    previous = previous;
}

void Node::input()
{
    cout << "Enter Incident ID: ";
    cin >> incident_id;
    cin.ignore();

    cout << "Enter User Account: ";
    getline(cin, user_account);

    cout << "Enter Type of Threat: ";
    getline(cin, threat_type);

    cout << "Enter Severity (critical/high/low): ";
    getline(cin, severity);

    cout << "Enter Time/Date of Detection: ";
    getline(cin, detection_time);

    cout << "Enter Status (active/resolved): ";
    getline(cin, status);

    cout << "Enter Analyst Name: ";
    getline(cin, analyst_name);
}

void Node::display()
{
    cout << "\n-----------------------------------";
    cout << "\nIncident ID: " << incident_id;
    cout << "\nUser Account: " << user_account;
    cout << "\nType of Threat: " << threat_type;
    cout << "\nSeverity: " << severity;
    cout << "\nDetection Time: " << detection_time;
    cout << "\nStatus: " << status;
    cout << "\nAnalyst Name: " << analyst_name;
    cout << "\n-----------------------------------" << endl;
}
