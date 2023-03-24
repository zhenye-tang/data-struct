#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static int find(void *id, struct node_st* node)
{
    if (*(int *)id == node->data.id) 
        return 0;
    else if (*(int*)id < node->data.id)
        return -1;
    else
        return 1;
}

int main(void)
{
    int arry[] = {1,2,3,7,6,5,9,8,4};
    struct student_info student;
    struct node_st* tree = NULL;


    for (int i = 0; i < sizeof(arry) / sizeof(*arry); i++)
    {
        student.id = arry[i];
        snprintf(student.name,NAMESIZE,"stu%d",arry[i]);
        student.chinese = rand() % 100;
        student.math = rand() % 100;
        insert_item(&tree, &student);
    }

    printf("--------------drow--------------\n");
    draw_tree(tree);
    printf("\n");

    printf("--------------drow balance tree--------------\n");
    balance_tree(&tree);
    draw_tree(tree);
    printf("\n");

    int id = 8;

    struct node_st* item = find_item(tree, &id, find);
    if (item != NULL)
    {
        printf("--------------find--------------\n");
        print_s(&item->data);
        printf("--------------------------------\n");
    }
    else
        printf("Can't find\r\n");

    draw_delete_item(&tree, 5);
    draw_tree(tree);
    travel(tree);
    printf("-----------layer_travel-------------\n");
    layer_travel(tree);

    exit(0);
}