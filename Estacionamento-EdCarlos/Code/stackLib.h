#ifndef STACK_A5
#define STACK_A5

typedef struct typeStack Tstack;

Tstack* create_stack(void);
int push(Tstack* stack, int inf);
int pop(Tstack* stack, int* temp);
int top(Tstack* stack, int* inf);
int isFull(Tstack* stack);
int isEmpty(Tstack* stack);
void destroy_stack(Tstack* stack);

int EDcarlos(void);

#endif