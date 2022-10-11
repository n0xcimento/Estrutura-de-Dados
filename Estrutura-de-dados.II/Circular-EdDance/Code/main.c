#include <stdio.h>
#include "header.h"

int main(void){
	List *xlist=list_create();
	List *jay=list_create();
	int qtychair, qtysec, sec;

	scanf("%d%d", &qtychair, &qtysec);

	while(0<qtysec--){
		scanf("%d", &sec);
		list_insertend(jay, sec);
	}

	for(int i=0; i<qtychair; i++){
		list_insertend(xlist, i+1);
		// list_insertbegin(xlist, v[i]);
	}

	printf("%d\n", EDdance(xlist, jay));

	return 0x00;
}