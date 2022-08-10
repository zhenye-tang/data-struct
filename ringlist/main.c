#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *list_creat(int n)
{
    struct node *mylist;
    struct node *cur;
    struct node *node;
    int i = 1;
    mylist = malloc(sizeof(*mylist));

    mylist->data = i;
    mylist->next = mylist;
    i++;
    cur = mylist;
    for( ; i <= n; i++)
    {
        node = malloc(sizeof(*node));
        node->data = i;
        node->next = mylist;

        cur->next = node;
        cur = node;
    }
    return mylist;
}

void list_show(struct node *list)
{
    struct node *mylist = list;
    
    for(mylist = list; mylist->next != list; mylist = mylist->next)
    {
        printf("%d ",mylist->data);
    }
    printf("%d\n",mylist->data);
}

int list_kill(struct node **list,int n)
{
    struct node *cur = *list,*node;
    int i = 1;

    while (cur != cur->next)
    {
        while(i < n)
        {
            node = cur;
            cur = cur->next;
            i++;
        }
        printf("%d ",cur->data);
        node->next = cur->next;
        free(cur);
        cur = node->next;
        i = 1;
    }
    *list = cur;
    printf("\n");
}


int main(int argc ,char *argv)
{

    struct node *mylist = list_creat(8);
    list_show(mylist);
    list_kill(&mylist,3);
    list_show(mylist);
    return 0;
}