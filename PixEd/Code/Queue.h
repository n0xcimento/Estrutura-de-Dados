#ifndef Queue_H
#define Queue_H

typedef struct typeQueue Fila;
typedef struct typePix Pix;

Fila* Fila_create(void);
int Fila_enqueue(Fila *fila);
int Fila_dequeue(Fila *fila, Pix *temp);
int Fila_destroy(Fila *fila);
int Fila_Qty(Fila *fila);

int isFull(Fila *fila);
int isEmpty(Fila *fila);

int PixED(void);
#endif