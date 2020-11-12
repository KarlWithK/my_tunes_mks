#include "shux.h"
#include "song.h"
#include <stdio.h>

int main() {
  char linebreak[] = "====================================";
  struct library *lib = new_lib();
  struct song *test = new_song("Whip", "JCole");
  lib = lib_add_song(lib, test);
  print_list(lib->position[9]);

  lib_print_random(lib);
  /* lib_print_by_letter(lib, 'j'); */
  /* lib_clear_all(lib); */
  /* lib_free(lib); */
  /* struct song *bruh = new_song("What", "JCole"); */
  /* test = insert_sorted(test, bruh); */
  /* printf("%d\n", strcmp("Ab", "Whip")); */
  /* lib->position[0] = insert_sorted(lib->position[0], test); */
  /* lib->position[0] = insert_sorted(lib->position[0], new_song("Ab", "JCole")); */
  /* print_list(test); */
  /* test = remove_song(test, bruh); */
  /* print_list(test); */
  /* /1* lib_free(lib); *1/ */
  /* free_list(test); */
}

/* char a = 'A';*/
/* printf("char: %c and num: %d\n",a,a);*/
/* struct library * lib1= new_lib();*/
/* lib1->position[0]=new_song("ATM", "JCole");*/
/* lib1->position[1]=new_song("Bob", "bobby");*/

/* lib_print_all(lib1);*/

/* printf("\n\nRandom Find Test\n\n");*/
/* * random_find test*/
/* struct song* s = new_song("h","A");*/
/* struct song* k = new_song("h","B");*/
/* struct song* h = new_song("h","C");*/
/* struct song* z = new_song("h","D");*/
/* s->next = k;*/
/* k->next = h;*/
/* h->next = z;*/

/* printf("%s\n", random_find(s)->artist);*/
/*



 return 0;*/
/* } */
