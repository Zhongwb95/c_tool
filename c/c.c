
#include <stdio.h>
#include "constrier.h"
#include "parsedie.h"


typedef struct{
    int x;
    char *tag;
    float z;
}PP;

int main(int argc, char const *argv[])
{
    LinkList *list = get_linklist();
    int i;
    for(i=0;i<10;i++){
        PP *p = malloc(sizeof(PP));
        p->x = i + i;
        p->tag = "i * i";
        p->z = 2.0 * i / 3;
        append_to_linklist(p, list);
    }
    Node *node;
    PP *die_list[list->len];
    LinkList *struct_list = get_linklist();
    LinkList *tpdef_list = get_linklist();
    i = 0;
    for(node = list->start_node;i<list->len;i++){
        die_list[i] = node->data;
        if (die_list[i]->tag == "i * i"){
        	append_to_linklist(die_list[i], struct_list);
        }else if (die_list[i]->tag == "i *i"){
        	append_to_linklist(die_list[i], tpdef_list);
        }

        printf("%d %s %f \n", die_list[i]->x, die_list[i]->tag, die_list[i]->z);
        node = node->next_node;
    }



    return 0;
}