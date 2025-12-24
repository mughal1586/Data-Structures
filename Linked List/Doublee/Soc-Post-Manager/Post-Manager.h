#include "Post.h"

using namespace std;

class PostManager
{
private:
    Post *head;
    Post *tail;
    int count;

public:
    PostManager();

    void new_post();
    void view_posts();
    void view_newer_post();
    void view_by_privacy();
    void view_all();
    void navigate_posts(Post *);
    void edit_post(Post *);
    void delete_post(Post *&);
    bool is_empty();
};