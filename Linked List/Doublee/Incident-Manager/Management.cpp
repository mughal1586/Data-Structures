#include "Management.h"

using namespace std;

Management::Management()
{
    head = NULL;
    tail = NULL;
}

bool Management::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

void Management::insertAtHead(Node &record)
{
    Node *temp = new Node();
    temp->set_incident_id(record.get_incident_id());
    temp->set_user_account(record.get_user_account());
    temp->set_threat_type(record.get_threat_type());
    temp->set_severity(record.get_severity());
    temp->set_detection_time(record.get_detection_time());
    temp->set_status(record.get_status());
    temp->set_analyst_name(record.get_analyst_name());

    if (isEmpty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->set_next(head);
        head->set_previous(temp);
        head = temp;
    }
}

void Management::insertAtTail(Node &record)
{
    Node *temp = new Node();
    temp->set_incident_id(record.get_incident_id());
    temp->set_user_account(record.get_user_account());
    temp->set_threat_type(record.get_threat_type());
    temp->set_severity(record.get_severity());
    temp->set_detection_time(record.get_detection_time());
    temp->set_status(record.get_status());
    temp->set_analyst_name(record.get_analyst_name());

    if (isEmpty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->set_next(temp);
        temp->set_previous(tail);
        tail = temp;
    }
}

void Management::insertAtTarget(Node &target, Node &record)
{
    if (isEmpty())
    {
        cout << "\nList is empty !!!" << endl;
        return;
    }

    Node *found = search(target.get_incident_id());

    if (found == NULL)
    {
        cout << "\nTarget not Found !!!" << endl;
        return;
    }

    else if (found == head)
    {
        insertAtHead(record);
    }

    else
    {
        Node *temp = new Node();
        temp->set_incident_id(record.get_incident_id());
        temp->set_user_account(record.get_user_account());
        temp->set_threat_type(record.get_threat_type());
        temp->set_severity(record.get_severity());
        temp->set_detection_time(record.get_detection_time());
        temp->set_status(record.get_status());
        temp->set_analyst_name(record.get_analyst_name());

        Node *previous = found->get_previous();

        found->set_previous(temp);    // Set temp address to target's previous Connection : (Target ---> Temp)
        previous->set_next(temp);     // Set temp address to previous block's next Connection : (Previous ---> Temp)
        temp->set_previous(previous); // Set previous address to temp's previous Connection : (Temp ---> Previous)
        temp->set_next(found);        // Set target address to temp's next Connection : (Temp ---> Target)
    }
}

void Management::remove_incident(int id)
{
    if (isEmpty())
    {
        cout << "\nNo records to remove !!!" << endl;
        return;
    }

    Node *target = search(id);

    if (target == NULL)
    {
        cout << "\nIncident not found !!!" << endl;
        return;
    }
    else if (target == head)
    {
        head = head->get_next();
        if (head != NULL)
            head->set_previous(NULL);
        target->set_next(NULL);
        delete target;
    }
    else if (target == tail)
    {
        tail = tail->get_previous();
        if (tail != NULL)
            tail->set_next(NULL);
        target->set_previous(NULL);
        delete target;
    }
    else
    {
        Node *prev = target->get_previous();
        Node *next = target->get_next();

        prev->set_next(next);
        next->set_previous(prev);
        target->set_next(NULL);
        target->set_previous(NULL);
        delete target;
    }

    cout << "\nIncident removed successfully." << endl;
}

Node *Management::search(int id)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->get_incident_id() == id)
            return temp;

        temp = temp->get_next();
    }

    return NULL;
}

void Management::highest_severity(string status_filter, string severity_level)
{
    Node *temp = head;
    Node *most_severe = NULL;

    while (temp != NULL)
    {
        if (temp->get_status() == status_filter && temp->get_severity() == severity_level)
        {
            most_severe = temp;
            break;
        }
        temp = temp->get_next();
    }

    if (most_severe != NULL)
    {
        cout << "\nMost severe active incident found:\n";
        most_severe->display();
    }
    else
    {
        cout << "\nNo matching active incident found !!!" << endl;
    }
}

void Management::printAll()
{
    Node *temp = head;

    if (isEmpty())
    {
        cout << "\nNo incidents to display !!!" << endl;
        return;
    }

    while (temp != NULL)
    {
        temp->display();
        temp = temp->get_next();
    }
}

void Management::printReverse()
{
    Node *temp = tail;

    if (isEmpty())
    {
        cout << "\nNo incidents to display !!!" << endl;
        return;
    }

    while (temp != NULL)
    {
        temp->display();
        temp = temp->get_previous();
    }
}

Node *Management::get_tail()
{
    return tail;
}
