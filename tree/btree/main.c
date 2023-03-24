#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE            (8)

struct student_info
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

struct node_st
{
    struct student_info data;
    struct node_st* l;
    struct node_st* r;
};

static int insert(struct node_st **root, struct student_info *data)
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
        return insert(&(*root)->l,data);
    return insert(&(*root)->r, data);
}

static struct student_info* find(struct node_st* root, int id)
{
    if (root == NULL)
        return NULL;

    if (id == root->data.id)
        return &root->data;

    if (id < root->data.id)
        return find(root->l, id);
    return find(root->r,id);
}

static void print_s(struct student_info* stu)
{
    printf("%d %s %d %d \n", stu->id, stu->name, stu->chinese, stu->math);
}

void drow_(struct node_st* tree_root, int level)
{
    if (tree_root == NULL)
        return;

    drow_(tree_root->r,level+1);

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }

    print_s(&tree_root->data);

    drow_(tree_root->l,level+1);
}

int draw(struct node_st* tree_root)
{
    drow_(tree_root,0);
}

int main(void)
{
    int arry[] = {1,2,3,7,6,5,9,8,4};
    int i = 0;
    struct node_st* tree = NULL;
    struct student_info temp;
    struct student_info* student;

    printf("--------------drow--------------\n");

    for (i = 0; i < sizeof(arry) / sizeof(*arry); i++)
    {
        temp.id = arry[i];
        snprintf(temp.name,NAMESIZE,"stu%d",arry[i]);
        temp.chinese = rand() % 100;
        temp.math = rand() % 100;
        insert(&tree, &temp);
    }
    draw(tree);

    printf("\n");
    printf("--------------find--------------\n");
    print_s(find(tree, 3));

    exit(0);
}