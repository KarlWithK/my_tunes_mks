#include <stdio.h>
#include "shux.h"

int main() {
	struct song* lib=new_lib;
	printf("Address: %p\n",lib);
	printf("Address: %p\n",lib+1);
	printf("Address: %p\n",lib+2);
	printf("Size: %d\n",sizeof(struct string *));

	struct song *shux[27];
	for(int i = 0; i < 27; i++) {
		shux[i] = NULL;
	}
	shux[0] = new_song("ATM", "JCole");
	print_list(shux[0]);
	struct song *free = free_list(shux[0]);
	return 0;
}
