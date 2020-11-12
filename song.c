#include "song.h"
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

void print_song(struct song *s) {
  if (s)
    printf("%s by %s, ", s->name, s->artist);
  else
    printf("node not found");
}

struct song *insert_front(struct song *s, char *n, char *a) {
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

struct song *find_song(struct song *s, char *n, char *a) {
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

struct song *random_find(struct song *s) {
  int len = 0;
  struct song *k = s;
  while (k) {
    len++;
    k = k->next;
  }
  srand(time(NULL));
  int i = rand() % len;
  /* printf("%i\n", i); */
  while (s) {
    if (!i)
      return s;
    i--;
    s = s->next;
  }
  return s;
}

// Implementation of this depends on whethe we want to pass "master" song struct
// address and which to remove, or just the one to remove and prev, or just one
// to remove and find the previous one sequentially in the function? Also do we
// want to return null, previous struct, or void?
struct song *remove_song(struct song *head, struct song *remove) {
  struct song *prev = NULL, *curr = head;
  while (curr) {
    if (head == remove) {
      curr = curr->next;
      free_song(head);
      if (curr)
        return curr;
    } else if (prev) {
      prev->next = curr->next;
      free(curr);
      return head;
    }
    curr = curr->next;
  }
  return NULL;
}

struct song *insert_sorted(struct song *head, struct song *new_song) {
  if (!head) {
    return insert_front(head, new_song->name, new_song->artist);
  }
  struct song *prev = NULL, *curr = head;
  while (curr) {
    if (!strcmp(curr->artist, new_song->artist)) {
      if (strcmp(curr->name, new_song->name) > 0) {
        new_song->next = curr;
        if (prev) {
          prev->next = new_song;
          return head;
        } else 
          return new_song;
      }
    } else if (strcmp(curr->artist, new_song->artist) > 0) {
      new_song->next = curr;
      if (prev) {
        prev->next = new_song;
        return head;
      } else {
        return new_song;
      }
    }
    prev = curr;
    curr = curr->next;
  }
  prev->next = new_song;
  return head;
}
