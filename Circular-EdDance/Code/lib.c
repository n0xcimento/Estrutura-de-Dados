#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct node{
	int x;
	struct node *next;
};

struct list{
	struct node *start;
};

//$ auxiliaries
No* noFill(int info){
	No *new=malloc(sizeof(No));
	if(new!=NULL){
		new->x=info;
		new->next=NULL; 
	}return new;
}

List* list_create(void){
	List *new=malloc(sizeof(List));
	if(new!=NULL){
		new->start=NULL;
	}return new;
}
//$

No* list_endno(List *xlist){
	No *aux=xlist->start;
	while(aux->next!=xlist->start)
		aux=aux->next;
	return aux;
}

int list_insertend(List *xlist, int info){
	No *new=noFill(info);

	if(xlist->start==NULL){
		xlist->start=new;
		new->next=new;
	}else{
		No *aux=xlist->start;
		while(aux->next!=xlist->start)
			aux=aux->next;
		new->next=aux->next;
		aux->next=new;
	}
}

int list_insertbegin(List *xlist, int info){
	No *new=noFill(info);

	 if(xlist->start==NULL){
		xlist->start=new;
		new->next=new;
	}else{
		No *aux=xlist->start;
		while(aux->next!=xlist->start)
			aux=aux->next;

		aux->next=new;
		new->next=xlist->start;
		xlist->start=new;
	}
}

int list_deleteno(List *xlist, int info){
	No *current=xlist->start, *before=NULL;

	if(current->x==info){
		No *end=list_endno(xlist);
		xlist->start=current->next;
		end->next=current->next;
		free(current);
	}else{

		while(current->x!=info && current->next!=xlist->start){
			before=current;
			current=current->next;
		}

		if(current->x==info){
			before->next=current->next;
			free(current);
		}
	}
}

int list_destroy(List *xlist, int info);

void list_print(List *xlist){
	No *aux=xlist->start;

	do{
		printf(" [%d] ->", aux->x);
		aux=aux->next;
	}while(aux!=xlist->start);
	puts(" ...");
}

void list_printLOOP(List *xlist){
	No *aux=xlist->start;

	for(int i=0; i<15; i++){
		printf(" [%d] ->", aux->x);
		aux=aux->next;
	}
	puts(" ...");
}


// ED 
int EDdance(List *xlist, List *jay){
	No *current=xlist->start, *before=NULL, *auxjay=jay->start;
	int i=0;

	while(current->next!=current){
		
		if(i==auxjay->x){
			before->next=current->next;
			free(current);
			current=before->next;
			before->next=current;
			auxjay=auxjay->next;
			i=0;
			continue;
		}
		before=current;
		current=current->next;
		i++;
	}return current->x;
}