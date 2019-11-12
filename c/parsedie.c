#include "parsedie.h"

int _init_dies(LinkList *list, LinkList *struct_list,
 				LinkList *typdef_list, ArrayList *all_dies);



int parse_die(LinkList *list){
	LinkList *struct_list = get_linklist();
	LinkList *typdef_list = get_linklist();
    ArrayList *all_dies = get_arraylist(list->len);
    _init_dies(list, struct_list, typdef_list, all_dies);


};



