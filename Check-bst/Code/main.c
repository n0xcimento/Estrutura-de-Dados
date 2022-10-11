#include <stdio.h>
#include <stdlib.h>
#include "TreeHeader.h"

int main(void){
	Tree *tree=BinTree_create();
	char buffer[4096], *pt=buffer;
	int v[1024]={0}, count=0;

	fgets(buffer, 4096, stdin);

	BinTree_insert_r(&(tree->root), &pt);
	BinTree_inorder_array(tree->root, v, &count);

	// verificar se os valores do vetor estão em ordem crescente
	for(int i=1; i<count; i++){
		if(v[i-1]>v[i]){
			puts("notBst");
			exit(0x01);
		}
	}puts("bst");

	return 0x00;
}