#include "shux.h"
#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_correct_index(struct song *s) {
  char first_letter = s->artist[0];
  if (first_letter > 90)
    first_letter -= 32;
  if (first_letter < 65 || first_letter > 90) {
    return 26;
  } else {
    first_letter -= 65;
    return first_letter;
  }
}

// LIBRARY!!!
struct library *new_lib() {
  struct library *lib = malloc(sizeof(struct library));
  int i;
  for (i = 0; i < 27; i++)
    lib->position[i] = NULL;
  return lib;
}

struct library *lib_add_song(struct library *lib, struct song *to_add) {
  int correct = get_correct_index(to_add);
  lib->position[correct] = insert_sorted(lib->position[correct], to_add);
  return lib;
}

struct song *lib_find_song(struct library *lib, char *n, char *a) {
  struct song *ret;
  int i;
  for (i = 0; i < 27; i++) {
    ret = find_song(lib->position[i], n, a);
    if (!ret)
      break;
  }
  return ret;
}

void lib_find_artist(struct library *lib, char *a) {
  int i;
  for (i = 0; i < 27; i++) {
    if (find_firstS(lib->position[i], a))
      printf("%c was found in the library!", *a);
  }
  printf("%c was NOT found in the library.", *a);
}

void lib_print_by_letter(struct library *lib, char l) {
  // Caps
  if (l >= 65 && l <= 90)
    print_list(lib->position[l - 65]);
  // Smol
  else if (l >= 97 && l <= 122)
    print_list(lib->position[l - 97]);
  // Special Characters
  else
    print_list(lib->position[26]);
}

void lib_print_by_artist(struct library *lib, char *a) {
  int correct = a[0];
  if (correct > 90)
    correct -= 32;
  correct = (correct < 65 || correct > 90) ? 26 : correct - 65;
  if (lib->position[correct]) {
    struct song *curr = find_firstS(lib->position[correct], a);
    if (!curr) {
      printf("%s is not in Shux!\n", a);
    } else {
      while (curr && !strcmp(curr->artist, a)) {
        print_song(curr);
        curr = curr->next;
      }
    }
  } else {
    printf("%s is not in Shux!\n", a);
  }
}

void lib_print_all(struct library *lib) {
  int i;
  for (i = 0; i < 27; i++)
    print_list(lib->position[i]);
}

void lib_print_random(struct library *lib) {}

struct library *lib_delete_song(struct library *lib, struct song *to_delete) {
  int correct = get_correct_index(to_delete);
  if (lib->position[correct])
    lib->position[correct] = remove_song(lib->position[correct], to_delete);
  return lib;
}

struct library *lib_clear_all(struct library *to_clear) {
  int i;
  for (i = 0; i < 27; i++)
    to_clear->position[i] = free_list(to_clear->position[i]);
  return NULL;
}

struct library *lib_free(struct library *to_free) {
  int i;
  for (i = 0; i < 27; i++)
    free_list(to_free->position[i]);
  free(to_free);
  return NULL;
}
