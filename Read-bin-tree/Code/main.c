#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
	struct node *left;
	int key;
	struct node *right;
};
typedef struct node No;

void BinTree_print(No *root);
void BinTree_preorder(No *root);
void BinTree_inorder(No *root);

No* BinTree_create(void);
int BinTree_insert_r(No **root, char **buffer);
No* no_Fill(char **buffer);

int main(void){
	No *tree=NULL;
	char buffer[4096], *pt=buffer;

	// scanf("\n%4096[^\n]", buffer);
	fgets(buffer, 4096, stdin);

	BinTree_insert_r(&tree, &pt);
	BinTree_print(tree);

	return 0x00;
}

int BinTree_insert_r(No **root, char **buffer){
	if((*root)==NULL){
		*root=no_Fill(buffer);

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

No* no_Fill(char **buffer){
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

No* BinTree_create(void){
	No *new=malloc(sizeof(No));
	if(new!=NULL){
		new->left=NULL;
		new->right=NULL;
		new->key=0;
	}return new;
}

void BinTree_preorder(No *root){
  if(root != NULL){
    printf(" %d,", root->key);
    BinTree_preorder(root->left);
    BinTree_preorder(root->right);
  }
}
void BinTree_inorder(No *root){
  if(root != NULL){
    BinTree_inorder(root->left);
    printf(" %d,", root->key);
    BinTree_inorder(root->right);
  }
}
void BinTree_print(No *root){
	printf("PREORDER:");
	BinTree_preorder(root);
	putchar('\n');
	printf("INORDER:");
	BinTree_inorder(root);
	putchar('\n');
}
