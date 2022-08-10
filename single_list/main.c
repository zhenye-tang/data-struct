#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
    list *l;
    int i = 0;
    datatype arr[] = {12,10,5,1,68};
    l = list_creat();
    if(l == NULL)
        exit(1);
    
    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        //list_insert_at(l,0,&arr[i]);
        list_ordef_insert(l,&arr[i]);
    }
    int a = 10;
    list_display(l);
    list_delete(l,&a);
    list_display(l);
    list_destory(l);

    return 0;
}