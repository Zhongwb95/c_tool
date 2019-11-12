#ifndef _PARSEDIE_H_
#define _PARSEDIE_H_
#include "constrier.h"

int parse_die(LinkList *list);

int _init_dies(LinkList *list, LinkList *struct_list,
               LinkList *typdef_list, ArrayList *all_dies);


#endif