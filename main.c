#include "shux.h"
#include "song.h"
#include <stdio.h>

int main() {
  char linebreak[] = "====================================";
  struct library *lib = new_lib();
  printf("%s\n", "LINKED LIST TESTS");
  printf("%s\n", linebreak);
  struct song *test1 = new_song("ATM", "JCole");
  struct song *test2 = new_song("Heros", "David Bowie");
  struct song *test3 = new_song("Edge Cases", "%Case");
  struct song *test4 = new_song("Gernade", "Bruno Mars");
  struct song *test5 = new_song("Chunky", "Bruno Mars");
  lib = lib_add_song(lib, test1);
  lib = lib_add_song(lib, test2);
  lib = lib_add_song(lib, test3);
  lib = lib_add_song(lib, test4);
  lib = lib_add_song(lib, test5);
  printf("%s\n", "Testing print_list");
  print_list(lib->position[3]);
  /* lib_print_all(lib); */
  printf("%s\n", linebreak);
  printf("%s\n", "Testing print_node");
  print_song(test3);
  printf("\n%s\n", linebreak);
  printf("%s\n", "Testing find_node");
  printf("%s [%s : %s]\n", "looking for", test1->artist, test1->name);
  printf("%s %s : %s\n", "Node found!", test1->artist, test1->name);
  print_song(lib_find_song(lib, test1->name, test1->artist));
  printf("%s [%s : %s]\n", "looking for", test1->artist, "Photograph");
  printf("%s\n", "Node not found!");
  print_song(lib_find_song(lib, "Photograph", test1->artist));
  printf("\n%s\n", linebreak);
  printf("%s [%s]\n", "looking for", "Bruno Mars");
  lib_print_by_artist(lib, "Bruno Mars");
  printf("\n%s [%s]\n", "looking for", "BTS");
  lib_print_by_artist(lib, "BTS");
  printf("%s\n", linebreak);
  printf("%s\n", "Testing random");
  lib_print_random(lib);
  printf("%s\n", linebreak);
  printf("%s\n", "print_libary");
  lib_print_all(lib);
  printf("%s\n", linebreak);
  printf("%s\n", "Testing print_letter");
  lib_print_by_letter(lib, 'b');
  lib_clear_all(lib);
  lib_free(lib);

  /* lib_print_random(lib); */
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

/*



 return 0;*/
/* } */
