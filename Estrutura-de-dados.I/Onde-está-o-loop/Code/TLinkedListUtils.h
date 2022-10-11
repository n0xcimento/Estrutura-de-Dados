#ifndef TLINKED_LIST_UTILS_H
#define TLINKED_LIST_UTILS_H
#include "TLinkedList.h"
//-----------------------------------------------------
//Espaco para suas definições, funções extras
//-----------------------------------------------------
/*
Esta funcao devera retornar a altura do no, conforme instrucao do exercicio, 
no caso da existencia de loop, ou -1 caso a lista nao possua loop.
*/
int TLinkedList_hasLoop(TLinkedList*);

typedef struct typeList Tlist;
typedef struct typeNode Tnode;

Tlist* Tlist_create(void);
int insert_node(Tlist*, TNo*);
int isExist(Tlist* , TNo*);

Tnode* node_create(TNo*);
#endif