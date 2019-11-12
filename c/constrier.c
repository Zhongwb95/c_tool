#include "constrier.h"

Node *_get_node(void *obj){
    Node *node = malloc(sizeof(Node));
    node->data = obj;
    node->last_node = NULL;
    node->next_node = NULL;
    return node;
};

int insert_to_linklist(int i, void *obj, LinkList *list){
    Node *node = _get_node(obj);
    if (list->len == 0){
        list->start_node = node;
        list->end_node = node;
    }else{
        Node *l_node;
        Node *n_node;
        for(n_node=list->start_node;i>0;i--)
            n_node = n_node->next_node;
        l_node = n_node->last_node;
        node->last_node = l_node;
        node->next_node = n_node;
        n_node->last_node = node;
        if (l_node != NULL) l_node->next_node = node;
    }
    list->len += 1;
};

int append_to_linklist(void *obj, LinkList *list){
    if (list->len == 0) {
        insert_to_linklist(0, obj, list);
    }else{
        Node *node = _get_node(obj);
        Node *last_node = list->end_node;
        last_node->next_node = node;
        list->end_node = node;
        list->len += 1;
    } 
};

LinkList *get_linklist(){
    LinkList *list = malloc(sizeof(LinkList));
    list->len = 0;
    return list;
};

ArrayList *get_arraylist(int len){
    ArrayList *list = malloc(sizeof(ArrayList));
    list->len = 0;
    list->cap = len;
    list->array = malloc(sizeof(void*) * len);
    return list;
};