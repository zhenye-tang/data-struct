#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "queue.h"

static struct node_st* _find_item(struct node_st* root, void* key, cmp* cb)
{
    if (root == NULL)
        return NULL;

    if (cb(key, root) == 0)
        return root;

    if (cb(key, root) < 0)
        return find_item(root->l, key, cb);
    return find_item(root->r, key, cb);
}

struct node_st* find_item(struct node_st* root, void* key, cmp* cb)
{
    return _find_item(root, key, cb);
}

void print_s(struct student_info* stu)
{
    printf("%d %s %d %d \n", stu->id, stu->name, stu->chinese, stu->math);
}

static void drow_(struct node_st* tree_root, int level)
{
    if (tree_root == NULL)
        return;

    drow_(tree_root->r, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }

    print_s(&tree_root->data);

    drow_(tree_root->l, level + 1);
}

static int get_num(struct node_st* tree_root)
{
    if (tree_root == NULL)
        return 0;
    return get_num(tree_root->l) + 1 + get_num(tree_root->r);
}

static struct node_st* find_left_last(struct node_st* root)
{
    if (root->l == NULL)
        return root;
    return find_left_last(root->l);
}

static struct node_st* find_right_last(struct node_st* root)
{
    if (root->r == NULL)
        return root;
    return find_left_last(root->r);
}


static void turn_left(struct node_st** tree_root)
{
    struct node_st* cur = *tree_root;
    struct node_st* new_root = NULL;
    *tree_root = cur->r;
    new_root = *tree_root;
    cur->r = NULL;
#if 1
    find_left_last(new_root)->l = cur;
#else
    while (new_root->l != NULL)
    {
        new_root = new_root->l;
    }
    new_root->l = cur;
#endif
}

static void turn_right(struct node_st** tree_root)
{
    struct node_st* cur = *tree_root;
    struct node_st* new_root = NULL;
    *tree_root = cur->l;
    new_root = *tree_root;
    cur->l = NULL;
#if 1
    find_right_last(new_root)->r = cur;
#else
    while (new_root->r != NULL)
    {
        new_root = new_root->r;
    }
    new_root->r = cur;
#endif
}

void balance_tree(struct node_st** tree_root)
{
    if (*tree_root == NULL)
        return;

    int sub;
    while (1)
    {
        sub = get_num((*tree_root)->l) - get_num((*tree_root)->r);
        if (sub >= -1 && sub <= 1) // is balance
            break;
        if (sub < -1) // left spain, right is too many item
            turn_left(tree_root);
        else
            turn_right(tree_root); // right spain, left is too many item
    }

    balance_tree(&(*tree_root)->l); // balance root left
    balance_tree(&(*tree_root)->r); // balance root right
}

int insert_item(struct node_st** root, struct student_info* data)
{
    struct node_st* node;
    if (*root == NULL)
    {
        node = malloc(sizeof(struct node_st));
        if (node == NULL)
            return -1;

        node->data = *data;
        node->l = node->r = NULL;
        *root = node;
        return 0;
    }

    if (data->id <= (*root)->data.id)
        return insert_item(&(*root)->l, data);
    return insert_item(&(*root)->r, data);
}

void draw_tree(struct node_st* tree_root)
{
    drow_(tree_root, 0);
}

/* left is new root */
void draw_delete_item(struct node_st** tree_root, int id)
{
    struct node_st** node = tree_root;
    struct node_st* cur;

    while ((*node) != NULL && (*node)->data.id != id)
    {
        if ((*node)->data.id < id)
        {
            node = &(*node)->r;
        }
        else
        {
            node = &(*node)->l;
        }
    }

    if (*node == NULL)
        return;

    cur = *node;

    if ((*node)->l != NULL)
    {
        *node = (*node)->l;
        find_right_last(*node)->r = cur->r;
    }
    else
    {
        *node = (*node)->r;
    }

    cur->l = cur->r = NULL;
    free(cur);
}

/* medium travel */
void travel(struct node_st* tree_root)
{
    if (tree_root == NULL)
        return;
    print_s(&tree_root->data);
    travel(tree_root->l);
    travel(tree_root->r);
}

/* layer traver */
void layer_travel(struct node_st* tree_root)
{
    int ret = 0;
    queue_t continer = queue_create();
    struct node_st *item  = {0};
    if (continer == NULL)
    {
        return;
    }

    queue_enqueuq(continer, (datatype *)&tree_root);
    while (1)
    {
        ret = queue_dequeue(continer, (datatype *)&item);
        if (ret == -1)
            break;
        print_s(&item->data);
        if (item->l != NULL)
        {
            queue_enqueuq(continer, (datatype *)&item->l);
        }
        if (item->r != NULL)
        {
            queue_enqueuq(continer, (datatype*)&item->r);
        }
    }

    queue_destory(continer);
}









