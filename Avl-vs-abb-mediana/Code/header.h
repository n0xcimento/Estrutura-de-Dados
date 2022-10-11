#ifndef TREE
#define TREE 0XC

struct bstno{
	int key;
	struct bstno *left;
	struct bstno *right;
};
typedef struct bstno No;

struct bsttree{
	struct bstno *root;
};
typedef struct bsttree Tree;


struct avlno{
	int bal, key;
	struct avlno *left;
	struct avlno *right;
};
typedef struct avlno aNo;

struct avltree{
	struct avlno *root;
};
typedef struct avltree aTree;

// BST
Tree* tcreat(void);
void bpreorder(No *root, char *bstr);
int insertmed(No **root, int *V, int begin, int end);
void tpostorder(No *root);


// AVL
aTree* acreat(void);
int insAVL(int x, aNo **pt, int *h);
void case1(aNo **pt, int *h);
void case2(aNo **pt, int *h);
void apreorder(aNo *root, char *astr);

#endif