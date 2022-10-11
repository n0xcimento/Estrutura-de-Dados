#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "TreeHeader.h"

Tree* BinTree_create(void){
	Tree *new=malloc(sizeof(Tree));
	if(new!=NULL){
		new->root=NULL;
	}return new;
}

// BinTree parentheses
No* noFill_r(char **buffer){
	if(!isdigit(*(*buffer+1))){
		(*buffer)++;
		return 0;
	}	
	char *rmd=NULL;
	No *new=malloc(sizeof(No));
	new->left=NULL;
	new->right=NULL;
	new->key=(int)strtol(*buffer+1, &rmd, 10);
	*buffer=rmd;
	return new;
}

int BinTree_insert_r(No **root, char **buffer){
	if((*root)==NULL){
		*root=noFill_r(buffer);

		if(**(buffer)==')' || *root==NULL) return 0;

		if((*root)!=NULL){
			if(**(buffer)=='('){
				BinTree_insert_r(&(*root)->left, buffer);

				if(**(buffer)==')'){
					(*buffer)++;
					BinTree_insert_r(&(*root)->right, buffer);
					(*buffer)++;
					return 1;
				}
			}
		}
	}
}

void BinTree_inorder_array(No *root, int *v, int *n){
	if(root!=NULL){
		BinTree_inorder_array(root->left, v, n);
		v[(*n)++]=root->key;
		BinTree_inorder_array(root->right, v, n);
	}
}