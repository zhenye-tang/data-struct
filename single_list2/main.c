#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char *argv[])
{
    score student;
    score *student_x;
    list *mylist = NULL;
    int i = 0;

    for(i = 0; i < 5; i++)
    {
        student.id = i;
        snprintf(student.name,NAMESIZE,"stu%d",i);
        student.math = rand() % 101;
        student.chinese = rand() % 101;
        list_insert_tail(&mylist,&student);
    }
    list_show(mylist);
    list_delete(&mylist);
    list_show(mylist);
    student_x = list_find(mylist,2);
    if(student_x)
    {
        printf("%d %s %d %d\n",student_x->id,student_x->name,student_x->math,student_x->chinese);
    }

    list_destory(mylist);

    return 0;
}