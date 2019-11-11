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
git config --global user.name "nameVal"
typedef struct LinkList{
	int len;
	void *start_node;
	void *end_node;
	int (*insert)(int i,void *obj);
	int (*append)(void *obj);
}LinkList;


int insert(int i, void *obj){
		
		Node *node = malloc(sizeof(Node));
		node->data = obj;
		for(;i>0;i--){
			
		}
	};

int append(void *obj){
	    if(len == 0) insert(0, obj);
		Node *node = malloc(sizeof(Node));
		node->data = obj;
	};

LinkList *get_linklist(){
	LinkList *list;
	list->len = 0;
	list->append = append;
	list->insert = insert;
	
	return list;
};

DLLIMPORT void HelloWorld();

#endif
