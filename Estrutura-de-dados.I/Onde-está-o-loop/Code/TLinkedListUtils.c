#include "TLinkedListUtils.h"
#include "TLinkedList.h"

#include<stdio.h>
#include<stdlib.h>

struct typeNode{  
  struct node *addr; //endereço do nó da lista original
  int dado;
  struct typeNode *prox; //endereço do próximo nó
};

struct typeList{
  struct typeNode *inicio;
};

int count=0;
int TLinkedList_hasLoop(TLinkedList* list){
  Tlist* myList=Tlist_create();

  TNo* aux = TLinkedList_getInicio(list);
  while(aux){
    if(insert_node(myList, aux))
      aux=aux->prox;
    else
      return count; //retorna a altura do loop
  }
  return 0; //não há loop [OBS: coloquei zero(0) porque no pdf está para retornar 0]
}

Tlist* Tlist_create(void){
  Tlist* new_list=malloc(sizeof(Tlist));

  if(new_list){
    new_list->inicio=NULL;
  }return new_list;
}

int insert_node(Tlist* list, TNo* node){

  if(list->inicio==NULL)
    list->inicio=node_create(node);
  else{

    if(!isExist(list, node)){ //se o endereço de node não existir na lista, insere node
      Tnode*aux=list->inicio;
      while(aux->prox!=NULL){
        aux=aux->prox;
      }
      aux->prox=node_create(node); //insere node no final da lista
    }else
      return 0;//não inserido, endereço já existe
  }
  return 1;//node inserido
}

Tnode* node_create(TNo*node){

  Tnode* new_node=malloc(sizeof(Tnode));
  if(new_node){
    new_node->addr=node;
    new_node->dado=node->info;
    new_node->prox=NULL;
  }return new_node;
}

int isExist(Tlist* list, TNo* node){
  int c=1; //conta a altura de onde tá o Loop
  Tnode* aux0=list->inicio;

  while(aux0!=NULL){
    if(aux0->addr==node){
      count=c;
      return 1; //endereço de node já existe na list;
    }
    c++;
    aux0=aux0->prox;
  }
  return 0; //endereço de node não existe na list
}