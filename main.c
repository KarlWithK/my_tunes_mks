#include <stdio.h>
#include "shux.h"

int main() {
	struct song *shux[27];
	shux[0] = new_song("ATM", "JCole");
	print_list(shux[0]);
	struct song *free = free_list(shux[0]);
	return 0;
}
