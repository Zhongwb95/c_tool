#ifndef _CONSTRIER_H_
#define _CONSTRIER_H_
#include <stdlib.h>
typedef struct Node{
    void *last_node;
    void *data;
    void *next_node;
}Node;

typedef struct LinkList{
    int len;
    void *start_node;
    void *end_node;
}LinkList;

typedef struct ArrayList{
    int len;
    void **array;
}ArrayList;

int insert_to_linklist(int i, void *obj, LinkList *list);

int append_to_linklist(void *obj, LinkList *list);

LinkList *get_linklist();

ArrayList *get_arraylist(int len);

// void *get_node(int index, ArrayList *list)

#endif

