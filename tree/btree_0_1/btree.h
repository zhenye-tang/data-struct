#ifndef __BTREE__H__
#define __BTREE__H__

#define NAMESIZE            (8)

typedef int cmp(void*, struct node_st*);

struct student_info
{
    int id;
    int math;
    int chinese;
    char name[NAMESIZE];
};

struct node_st
{
    struct student_info data;
    struct node_st* l;
    struct node_st* r;
};

void balance_tree(struct node_st** tree_root);
int insert_item(struct node_st** root, struct student_info* data);
void draw_tree(struct node_st* tree_root);
void print_s(struct student_info* stu);
void draw_delete_item(struct node_st** tree_root, int id);
struct node_st* find_item(struct node_st* root, void* key, cmp* cb);
void travel(struct node_st* tree_root);
void layer_travel(struct node_st* tree_root);
#endif //__BTREE__H__