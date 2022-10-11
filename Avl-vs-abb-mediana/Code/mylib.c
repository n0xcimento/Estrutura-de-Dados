#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Tree* tcreat(void){
	Tree *new=malloc(sizeof(Tree));
	if(new!=NULL)
		new->root=NULL;
	return new;
}

No* nofill(int info){
	No *new=malloc(sizeof(No));
	if(new!=NULL){
		new->key=info;
		new->left=NULL;
		new->right=NULL;
	}return new;
}

void bpreorder(No *root, char *bstr){
	if(root!=NULL){
		char aux[8];
		sprintf(aux, " %d", root->key);
		strcat(bstr, aux);
		bpreorder(root->left, bstr);
		bpreorder(root->right, bstr);
	}
}

void apreorder(aNo *root, char *astr){
	if(root!=NULL){
		char aux[8];
		sprintf(aux, " %d", root->key);
		strcat(astr, aux);
		apreorder(root->left, astr);
		apreorder(root->right, astr);
	}
}

int insertmed(No **root, int *V, int begin, int end){
	if(end-begin<0){
		*root=NULL;
		return 0xc;
	}

	int med=(begin+end)/2;
	*root=nofill(V[med]);

	if(end-begin<=0) return 0xc;

	insertmed(&(*root)->left, V, begin, med-1);
	insertmed(&(*root)->right, V, med+1, end);
}

// avl
aTree* acreat(void){
	aTree *new=malloc(sizeof(aTree));
	if(new!=NULL){
		new->root=NULL;
	}return new;
}

aNo* nofill_avl(int info){
	aNo *new=malloc(sizeof(aNo));
	if(new!=NULL){
		new->key=info;
		new->bal=0;
		new->left=NULL;
		new->right=NULL;
	}return new;
}

int insAVL(int x, aNo **pt, int *h){
	if(*pt==NULL){
		*pt=nofill_avl(x);
		*h=1;
	}else{
		if((*pt)->key == x)
			return 0xc;

		if(x < (*pt)->key){
			insAVL(x, &(*pt)->left, h);
			if(h!=0){
				switch((*pt)->bal){
					case 1:
						(*pt)->bal=0;
						*h=0;
						break;

					case 0:
						(*pt)->bal=-1;
						break;

					case -1:
						case1(pt, h);
				}
			}
		}else{
			insAVL(x, &(*pt)->right, h);
			if(h!=0){
				switch((*pt)->bal){
					case -1:
						(*pt)->bal=0;
						*h=0;
						break;

					case 0:
						(*pt)->bal=1;
						break;

					case 1:
						case2(pt, h);
				}
			}
		}
	}
}

void case1(aNo **pt, int *h){
	aNo *ptu=(*pt)->left;
	if(ptu->bal==-1){
		(*pt)->left=ptu->right; ptu->right=*pt;
		(*pt)->bal=0; (*pt)=ptu;
	}else{
		aNo *ptv=ptu->right;
		ptu->right=ptv->left; ptv->left=ptu;
		(*pt)->left=ptv->right; ptv->right=*pt;

		if(ptv->bal==-1)
			(*pt)->bal=1;
		else
			(*pt)->bal=0;

		if(ptv->bal==1)
			ptu->bal=-1;
		else
			ptu->bal=0;
		*pt=ptv;
	}
	(*pt)->bal=0; *h=0;
}

void case2(aNo **pt, int *h){
	aNo *ptu=(*pt)->right;
	if(ptu->bal==1){
		(*pt)->right=ptu->left; ptu->left=*pt;
		(*pt)->bal=0; *pt=ptu;
	}else{
		aNo *ptv=ptu->left;
		ptu->left=ptv->right; ptv->right=ptu;
		(*pt)->right=ptv->left; ptv->left=*pt;
		if(ptv->bal==1)
			(*pt)->bal=-1;
		else
			(*pt)->bal=0;

		if(ptv->bal==-1)
			ptu->bal=1;
		else
			ptu->bal=0;
		*pt=ptv;
	}
	(*pt)->bal=0; *h=0;
}