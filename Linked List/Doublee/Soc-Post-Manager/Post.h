#include <iostream>
#include <string>

using namespace std;

class Post
{
private:
    string message;
    int share_with;
    string date;
    Post *previous;
    Post *next;

public:
    Post();
    Post(Post &);

    string get_message();
    void set_message(string);

    int get_share_with();
    void set_share_with(int);

    string get_date();
    void set_date(string);

    Post *get_previous();
    void set_previous(Post *);

    Post *get_next();
    void set_next(Post *);

    void insert();
    void display();
};