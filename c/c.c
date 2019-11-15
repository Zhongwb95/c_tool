#include <string.h>
#include <stdio.h>
#include "constrier.h"
#include "parsedie.h"


typedef struct{
    int x;
    char *tag;
    float z;
}PP;

int count = 0;

PP *_get_node_de(long x, long index, long mul, ArrayList *list){
    count += 1;
    PP *p = list->array[index];
    if(x == p->x) return p;
    else{
        mul = mul*2;
        long move_n = (long)(list->len/mul);
        if(move_n == 0) move_n = 1; // 0 is error
        if(x < p->x) index -= move_n;
        else index += move_n;
        return _get_node_de(x, index, mul, list);
    } 
}

PP *get_node(long x, ArrayList *list){
    long mul = 2;
    long index = (long)(list->len/mul);
    return _get_node_de(x, index, mul, list);
}

int main(int argc, char const *argv[])
{
    
    LinkList *list = get_linklist();
    int i;
    for(i=0;i<100000;i++){
        PP *p = malloc(sizeof(PP));
        p->x = i + i;
        p->tag = "i * i";
        p->z = 2.0 * i / 3;
        append_to_linklist(p, list);
    }
    Node *node;
    // LinkList *struct_list = get_linklist();
    // LinkList *tpdef_list = get_linklist();
    i = 0;

    ArrayList *ar_list = get_arraylist(list->len);
    for(node = list->start_node;i<list->len;i++){
        ar_list->array[i] = node->data; 
        node = node->next_node;
    }
    PP *p = get_node(13122, ar_list);
    
    printf("%d %f \n", p->x, p->z);
    printf("%d \n", count);

    printf("%f \n", 13122/2*2.0/3);


    // char *a = "ahb";
    // char *b = "abc";
    // printf("%d --- ", strncmp(a, b,3));

    return 0;
}