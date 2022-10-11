#ifndef EDDANCE
#define EDDANCE

typedef struct node No;
typedef struct list List;

List* list_create(void);
int list_insertend(List *xlist, int info);
int list_insertbegin(List *xlist, int info);
int list_deleteno(List *xlist, int info);
int list_destroy(List *xlist, int info);
void list_print(List *xlist);
void list_printLOOP(List *xlist);

int EDdance(List *xlist, List *jay);

#endif