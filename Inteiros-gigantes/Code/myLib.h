#ifndef BIG_INT_H
#define BIG_INT_H

typedef struct TypeNode Tnode;
typedef struct TypeDoubleList Tdlist;

Tdlist* create_list(void);
int insert_node(Tdlist*, int);
Tdlist* generate_list(char*);
Tdlist* sum_lists(Tdlist*, Tdlist*);
int print_rev_list(Tdlist*);

#endif