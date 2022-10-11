#ifndef SBS_HEADER
#define SBS_HEADER

typedef struct node No;
typedef struct linked_list List;

List *list_create(void);
No* noFill(int qty, int indx);
int list_insert(List *list, int qty_ref, int indx);

void encoder(List *xlist);
void coderPrint(List *list, size_t);

void decoder(List *xlist);
void decoderPrint(List *xlist);

#endif