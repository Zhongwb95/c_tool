#ifndef _CONSTRIER_H_
#define _CONSTRIER_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

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

int insert_to_linklist(int i, void *obj, LinkList *list){
        Node *node = malloc(sizeof(Node));
        node->data = obj;
        if (list->len == 0){
        	node->last_node = 0;
        	node->next_node = 1;
            list->start_node = node;
            list->end_node = node;
        }else{
        	Node *t_node;
        	Node *n_node;
            for(t_node=list->start_node;i>0;i--){
                t_node = t_node->next_node;
            }
            n_node = t_node->next_node;
            node->last_node = t_node;
            node->next_node = n_node;
            t_node->next_node = node;
            n_node->last_node = node;
        }
        list->len += 1;
    };

int append_to_linklist(void *obj, LinkList *list){
        if (list->len == 0) {
        	insert_to_linklist(0, obj, list);
		}else{
            Node *node = malloc(sizeof(Node));
            node->data = obj;
            node->next_node = 1;
            Node *last_node = list->end_node;
            last_node->next_node = node;
            list->end_node = node;
            list->len += 1;
        } 
    };

LinkList *get_linklist(){
    LinkList *list;
    list->len = 0;
    return list;
};






#endif
