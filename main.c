#include <stdio.h>
#include "shux.h"

int main() {
	struct song * lib= new_lib();

	/*
	struct song *shux[27];
	for(int i = 0; i < 27; i++) {
		shux[i] = NULL;
	}
	shux[0] = new_song("ATM", "JCole");
	print_list(shux[0]);
	struct song *free = free_list(shux[0]);
	*/

///* random_find test
	struct song* s = new_song("h","A");
	struct song* k = new_song("h","B");
	struct song* h = new_song("h","C");
	struct song* z = new_song("h","D");
	s->next = k;
	k->next = h;
	h->next = z;

	printf("%s\n", random_find(s)->artist);
	//*/



	return 0;
}
