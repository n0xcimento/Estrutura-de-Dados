#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct node{
	int qty_ref;
	int indx;
	struct node *next;
};

struct linked_list{
	char ref;
	int qty_no;
	struct node *start;
};


List* list_create(void){
	List *new_list=malloc(sizeof(List));
	if(new_list!=NULL){
		new_list->start=NULL;
		new_list->qty_no=0;
	}return new_list;
}

int list_insert(List *list, int qty_ref, int indx){
	if(list->start==NULL)
		list->start=noFill(qty_ref, indx);
	else{
		No *aux=list->start;
		while(aux->next!=NULL)
			aux=aux->next;
		aux->next=noFill(qty_ref, indx);
	}list->qty_no++;
	return list->qty_no;
}

No* noFill(int qty, int indx){
	No *new_no=malloc(sizeof(No));
	if(new_no!=NULL){
		new_no->qty_ref=qty;
		new_no->indx=indx;
	}return new_no;
}


void decoder(List *xlist){
	char buffer[100];
	int qty_ref, indx, qty_no;

	scanf("\n%c%d", &xlist->ref, &qty_no);

	for(int i=0; i<qty_no; i++){
		scanf("%d%d", &qty_ref, &indx);
		list_insert(xlist, qty_ref, indx);
	}
	decoderPrint(xlist);
}


void coderPrint(List *list, size_t len){
	if(list->start!=NULL){
		printf("%c %d\n", list->ref, list->qty_no);
		No *aux=list->start;
		while(aux!=NULL){
			printf("%d %d\n", aux->qty_ref, aux->indx);
			aux=aux->next;
		}putchar('\n');
		// printf("%ld\n", len - (list->qty_no*12+5));
	}
}


void encoder(List *xlist){
	char buffer[100];
	char ref;
	int i, indxi, indxf, qty;

	scanf("\n%[10]", buffer);
	ref=buffer[0];
	xlist->ref=ref;
	indxi=0;

	for(i=1; buffer[i]!='\0'; i++){

		if(buffer[i-1]==ref && buffer[i]!=ref){
			indxf=i;
			qty=indxf-indxi;
			list_insert(xlist, qty, indxi);
		}
		if(buffer[i-1]!=ref && buffer[i]==ref)
			indxi=i;
	}

	if(buffer[i-1]==ref){
		qty=i-indxi;
		list_insert(xlist, qty, indxi);
	}else{
		qty=i-indxf;
		list_insert(xlist, qty, -1);
	}

	coderPrint(xlist, strlen(buffer));
}



void decoderPrint(List *xlist){
	No *aux=xlist->start, *aft=NULL;

	char invRef = (xlist->ref=='1' ? '0' : '1');
	int i;

	while(aux!=NULL){
		i=0;
		while(i<aux->qty_ref){
			putchar(aux->indx >=0 ? xlist->ref : invRef);
			i++;
		}

		if(aux->next!=NULL){
			aft=aux->next;

			i=0;
			while(i < aft->indx - aux->qty_ref){
				putchar((xlist->ref=='0') ? '1' : '0');
				i++;
			}
		}
		aux=aux->next;
	}putchar('\n');
}