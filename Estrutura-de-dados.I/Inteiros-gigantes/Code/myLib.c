#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLib.h"

struct TypeNode{
	int inf;
	struct TypeNode* bef;
	struct TypeNode* next;
};

struct TypeDoubleList{
	struct TypeNode* start;
	struct TypeNode* last;
};

Tnode* create_node(int value){
	Tnode* node=malloc(sizeof(Tnode));
	if(node==NULL) return 0;

	node->inf=value;
	node->bef=NULL;
	node->next=NULL;
	return node;
}

Tdlist* create_list(void){
	Tdlist* list=malloc(sizeof(Tdlist));
	if(list==NULL) return 0;

	list->start=NULL;
	list->last=NULL;
	return list;
}

int insert_node(Tdlist* list, int value){
	Tnode* new_node=create_node(value);

	if(list->start==NULL){
		list->start=new_node;
		list->last=new_node;
	}else{
		new_node->bef=list->last;
		list->last->next=new_node;
		list->last=new_node;
	} return 1;
}

Tdlist* generate_list(char* buffer){
	Tdlist* new_list=create_list();
	unsigned int i=0, size=strlen(buffer);
	while(i<size)
		insert_node(new_list, buffer[i++]-48);
	return new_list;
}

Tdlist* sum_lists(Tdlist* l1, Tdlist* l2){
	Tdlist* sum=create_list();
	int carry=0;

	Tnode* aux1=l1->last;
	Tnode* aux2=l2->last;
	while(aux1!=NULL || aux2!=NULL){

		if(aux1!=NULL && aux2!=NULL){
			insert_node(sum, carry+(aux1->inf+aux2->inf)%10);
			carry=(carry+aux1->inf+aux2->inf)/10;
			aux1=aux1->bef;
			aux2=aux2->bef;
		}else{
			if(aux1!=NULL){
				insert_node(sum, carry+(aux1->inf)%10);
				carry=(carry+aux1->inf)/10;
				aux1=aux1->bef;
			}else{
				insert_node(sum, carry+(aux2->inf)%10);
				carry=(carry+aux2->inf)/10;
				aux2=aux2->bef;
			}
		}
	}
	if(carry>0)
		insert_node(sum, carry);
	return sum;
}

int print_rev_list(Tdlist* list){
	Tnode* aux=list->last;

	while(aux){
		printf("%d", aux->inf);
		aux=aux->bef;
	}putchar('\n');
	return 1;
}