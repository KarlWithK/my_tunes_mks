#include <stdio.h>
#include "shux.h"

int main() {
	struct library * lib1= new_lib();
	lib1->position[0]=new_song("ATM", "JCole");
	lib1->position[1]=new_song("Bob", "bobby");

	print_list(lib1->position[0]);
	print_list(lib1->position[1]);
	print_list(lib1->position[2]);
	print_list(lib1->position[3]);
	print_list(lib1->position[4]);
	print_list(lib1->position[5]);







	printf("\n\nRandom Find Test\n\n");
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
