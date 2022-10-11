#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"

struct typeNode{
	int data;
	struct typeNode *next;
};

struct typeList{
	Tnode *start;
};

Tnode* last_node(Tlist* list){
	Tnode* aux=list->start;
	while(aux->next!=list->start)
		aux=aux->next;
	return aux;
}

Tnode* node_create(int value){
	Tnode* node=malloc(sizeof(Tnode));
	if(node){
		node->data=value;
		node->next=node;
	}return node;
}

Tlist* list_create(void){
	Tlist* new_list=malloc(sizeof(Tlist));
	if(new_list)
		new_list->start=NULL;
	return new_list;
}

int insert_end(Tlist* list, int value){
	Tnode* new_node=node_create(value);
	if(list==NULL) return 0;

	if(list->start==NULL)
		list->start=new_node;
	else{
		Tnode* aux=list->start;
		while(aux->next!=list->start)
			aux=aux->next;

		aux->next=new_node;
		new_node->next=list->start; //era NULL nas listas anteriores
	}
	return 1;
}


/////////////A3////////////////
int EDmundo(int N, int M){
	Tlist *list=list_create();
	int count=1;

	while(count<=N)
		insert_end(list, count++);

	Tnode* last=last_node(list);
	Tnode* aux=last->next;
	while(last!=last->next){
		count=1;
		while(count<=M){
			if(count==M){
				last->next=aux->next;
				free(aux);
				aux=last->next;
				break;
			}	
			last=aux;
			aux=aux->next;
			count++;
		}
	} return last->data;
}