#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

struct typePix{
	int id_orig, id_dest;
	float valor;
	Pix *next;
};

struct typeQueue{
	Pix *tail;
	int qty, MAX;
};

Pix* Pix_create(void){
	Pix *novo=malloc(sizeof(Pix));
	if(!novo) return 0;

	scanf("%d%d%f", &novo->id_orig, &novo->id_dest, &novo->valor);
	if(novo->id_dest==0 && novo->id_orig==0)
		return 0;
	else{
		novo->next=novo;
		return novo;
	}
}

Fila* Fila_create(void){
	Fila *new=malloc(sizeof(Fila));
	if(!new) return 0;

	new->tail=NULL;
	new->qty=0;
	return new;
}

int Fila_enqueue(Fila *fila){
	Pix *new=Pix_create();
	if(!new) return 0; // there is no memory

	if(fila->tail==NULL)
		fila->tail=new;
	else{
		new->next=fila->tail->next;
		fila->tail->next=new;
		fila->tail=new;
	}fila->qty++;
	return 1;
}

int Fila_dequeue(Fila *fila, Pix *temp){
	if(isEmpty(fila)) return 0;

	Pix *oldHead=fila->tail->next;
	*temp=*oldHead;
	fila->tail->next=oldHead->next;
	free(oldHead);
	fila->qty--;
	if(fila->qty==0)
		fila->tail=NULL;
	return 1;
}

int Fila_destroy(Fila *fila){
	if(!isEmpty(fila)){
		Pix *head=fila->tail->next;
		while(head!=fila->tail && head){
			fila->tail->next=head->next;
			free(head);
			head=fila->tail->next;
		}
		free(fila->tail);
	}
	free(fila);
	return 1;
}

int Fila_Qty(Fila *fila){
	return fila->qty;
}

int isEmpty(Fila *fila){
	return fila->tail==NULL;
}

int PixED(void){
	Fila *f4=Fila_create();
	Pix temp;

	scanf("%d", &f4->MAX);
	if(f4->MAX<=0) return 0;

	while(Fila_enqueue(f4)){
		
		if(f4->qty==f4->MAX){
			while(Fila_dequeue(f4, &temp))
				printf("(%d, %d, %.2f),", temp.id_orig, temp.id_dest, temp.valor);
			putchar('\n');
		}
	}
	if(f4->qty>0){
		while(Fila_dequeue(f4, &temp))
			printf("(%d, %d, %.2f),", temp.id_orig, temp.id_dest, temp.valor);
		putchar('\n');
	}
	Fila_destroy(f4);

	return 1;
}