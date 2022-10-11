#include <stdio.h>
#include "header.h"

int main(void){
	List *l1=list_create();
	char mode;

	scanf("\n%c", &mode);

	if(mode=='c')
		encoder(l1);
	else
		decoder(l1);

	return 0x00;
}

