#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int* insertionSort(int *v, int len){
	int *cp=malloc(len*sizeof(int));
	cp[0]=v[0];

	int i,j,atual;
	for(i=1; i<len; i++){
		atual=v[i];
		for(j=i; j>0 && atual<cp[j-1]; j--)
			cp[j]=cp[j-1];
		cp[j]=atual;
	}return cp;
}

int main(void){
	int A[2048]={0}, qty, i=0, *cp=NULL;
	
	scanf("%d", &qty);
	while(i<qty)
		scanf("%d", &A[i++]);

	Tree *bst=tcreat();
	aTree *avl=acreat();

	cp=insertionSort(A, qty);

//$bst by median
	insertionSort(A, qty);
	insertmed(&(bst->root), cp, 0, qty-1);

	char outbst[64]="";
	// puts("bst:");
	bpreorder(bst->root, outbst);
	// puts(outbst);

//$avl
	for(int h=0,i=0; i<qty; i++)
		insAVL(A[i], &(avl->root), &h);

	char outavl[64]="";
	// puts("\nalv:");
	apreorder(avl->root, outavl);
	// puts(outavl);

	if(strcmp(outbst, outavl))
		puts("0");
	else
		puts("1");

	return 0x00;
}