#include "stackLib.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

struct typeStack{
	int data[MAX];
	int  qt;
};

Tstack* create_stack(void){
	Tstack* new=malloc(sizeof(Tstack));
	if(!new) return 0; 

	new->qt=-1;
	return new;
}

int push(Tstack* stack, int inf){
	if(!isFull(stack)){
		stack->data[++stack->qt]=inf;
		return 1;
	}puts("Overflow");
	return 0;
}

int pop(Tstack* stack, int* temp){
	if(!isEmpty(stack)){
		*temp=stack->data[stack->qt--];
		return 1;
	}return 0; //puts("Underflow");
}

int top(Tstack* stack, int* inf){
	if(!isEmpty(stack)){
		*inf=stack->data[stack->qt];
		return 1;
	}return 0;
}

void destroy_stack(Tstack* stack){
	free(stack);
}

int isFull(Tstack* stack){
	return stack->qt==MAX-1;
}

int isEmpty(Tstack* stack){
	return stack->qt==-1;
}

int EDcarlos(void){
	Tstack *est1=create_stack(), *est2=create_stack();
	char cmd;
	int value, temp, ret;

	do{
		scanf("\n%c%d", &cmd, &value);

		switch(cmd){

			case '0':
				destroy_stack(est1);
				destroy_stack(est2);
				break;

			case 'i':
				push(est1, value);
				break;

			case 'r':
				while(ret=pop(est1, &temp)){
					printf("%d,", temp);
					if(temp==value) break;
					push(est2, temp);					
				}printf("%s\n", (ret==0)?"Underflow":"");

				while((pop(est2, &temp)) && (temp!=-1)){
					push(est1, temp);
				}
			break;
		}

	}while(cmd!='0');
	return 1;
}
