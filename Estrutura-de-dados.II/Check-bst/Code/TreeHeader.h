#ifndef BINTREE
#define BINTREE

struct node{
	int key;
	struct node *p;
	struct node *left;
	struct node *right;
};
typedef struct node No;

struct tree{
	No *root;
};
typedef struct tree Tree;

Tree* BinTree_create(void);
void BinTree_insert_g(Tree *T, int key);
void BinTree_inorder(No *root);
void BinTree_preorder(No *root);

// BinTree parentheses
int BinTree_insert_r(No **root, char **buffer);
void BinTree_inorder_array(No *root, int *v, int *n);

#endif