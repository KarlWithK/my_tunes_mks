#include "shux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song *new_song(char *n, char *a) {
  struct song *np = malloc(sizeof(struct song));

  np->name = strdup(n);
  np->artist = strdup(a);
  np->next = NULL;
  return np;
}

struct song *insert_front(struct song *s, char *a, char *n) {
  struct song *np = new_song(n, a);
  np->next = s;
  return np;
}

struct song *free_song(struct song *s) {
  free(s->artist);
  free(s->name);
  free(s);
  return NULL;
}

struct song *find_song(struct song *s, char *a, char *n) {
  while (s) {
    if (!strcmp(s->artist, a) && !strcmp(s->name, n))
      return s;
    s = s->next;
  }
  return NULL;
}

struct song *find_firstS(struct song *s, char *a) {
  while (s) {
    if (!strcmp(s->artist, a))
      return s;
    s = s->next;
  }
  return NULL;
}

void print_list(struct song *s) {
  printf("[");
  while (s) {
    printf("%s by %s, ", s->name, s->artist);
    s = s->next;
  }
  printf("]\n");
}


struct song *free_list(struct song *song) {
  struct song *curr = song;
  while (curr) {
    curr = curr->next;
    free_song(song);
    song = curr;
  }
  return song;
}

/* struct song *random_find(struct song *s) { */
/*   srand(time(NULL)); */
/*   int i = rand() % 100; */
/* } */
