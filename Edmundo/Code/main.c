#include <stdio.h>
#include "myLib.h"

int main(){
	int test, M, N;

	scanf("%d", &test);

	while(test-->0){
		scanf("%d%d", &N, &M);
		printf("%d\n", EDmundo(N, M));
	}
	return 0x00;
}