#include <stdio.h>
#include <string.h>
#include "myLib.h"

int main(){
	char buffer[4097];
	Tdlist *list1=NULL, *list2=NULL, *soma=NULL;
	int ncases;

	scanf("%d", &ncases);

	while(0<ncases--){

		scanf("%4096s", buffer);
		list1=generate_list(buffer);

		scanf("%4096s", buffer);
		list2=generate_list(buffer);

		soma=sum_lists(list1, list2);

		print_rev_list(soma);
	}
}