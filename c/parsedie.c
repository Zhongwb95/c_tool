#include <string.h>
#include "parsedie.h"

typedef struct {
	int tag;
	int offset;
	char *AT_decl_file;
}DIE;

int _init_dies(LinkList *list, LinkList *struct_list,
 			LinkList *typdef_list, ArrayList *all_dies){

};


int is_start_with(char *sys_str, char *str){
	return strncmp(sys_str, str, strlen(sys_str));
};

int is_sys(char *file_entry){
    char *sys_str[] = {"/usr/","/opt/"};
    int i = 2;
    int flag = 0;
    for(;i>0;i--){
    	char *sys_s = sys_str[i-1];
    	flag += is_start_with(sys_str[i-1], file_entry);
    }

};

int parse_struct(LinkList *struct_list, LinkList *typdef_list, ArrayList *all_dies){
	Node *node;
	int i = 0;
	for(node=struct_list->start_node;i<struct_list->len;i++){
		DIE *die = node->data;
		node = node->next_node;
		if (is_sys(die->AT_decl_file)==1) continue;

	}
};


// DIE *get_node(long offset, ArrayList *list){
// 	DIE *die 
// 	if
// };


int parse_die(LinkList *list){
	LinkList *struct_list = get_linklist();
	LinkList *typdef_list = get_linklist();
    ArrayList *all_dies = get_arraylist(list->len);
    _init_dies(list, struct_list, typdef_list, all_dies);
    parse_struct(struct_list, typdef_list, all_dies);


};



