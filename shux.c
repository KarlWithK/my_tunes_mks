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
   while(k){
     len++;
     k = k->next;
   }
   srand(time(NULL));
   int i = rand() % len;
   printf("%i\n",i);
    while (s){
      if(!i) return s;
      i--;
      s = s->next;
    }
  return s;
 } 

//Implementation of this depends on whethe we want to pass "master" song struct address and which to remove, 
//or just the one to remove and prev, or just one to remove and find the previous one sequentially in the function?
//Also do we want to return null, previous struct, or void?
struct song *remove_song(struct song* song, struct song* prev_song) {
	prev_song->next=song->next;
	free_song(song);
	return prev_song;
}


//LIBRARY!!!
struct library * new_lib() {
	struct library * lib=malloc(sizeof(struct library));
	int i;
	for(i=0;i<27;i++)
		lib->position[i]=NULL;
	return lib;
}

struct library * lib_add_song(struct library * lib, struct song * to_add){

}

struct song * lib_find_song(struct library * lib, char *n,char *a){
	struct song * ret;
	int i;
	for(i=0;i<27;i++){
		ret=find_song(lib->position[i], n, a);
		if(!ret)
			break;
	}
	return ret;
}

void lib_find_artist(struct library * lib, char *a){
	int i;
	for(i=0;i<27;i++){
		if(find_firstS(lib->position[i], a))
			printf("%c was found in the library!", a);
	}
	printf("%c was NOT found in the library.", a);
}

void lib_print_by_letter(struct library * lib, char l){

}

void lib_print_by_artist(struct library * lib, char *a){

}

void lib_print_all(struct library * lib){
	int i;
	for(i=0;i<27;i++)
		print_list(lib->position[i]);
}

void lib_print_random(struct library *lib){

}

struct library * lib_delete_song(struct library * lib, struct song * to_delete){

}

struct library * lib_clear_all(struct library * to_clear){
	int i;
	for(i=0;i<27;i++)
		to_clear->position[i]=free_list(to_clear->position[i]);
}

struct library * lib_free(struct library * to_free){
	int i;
	for(i=0;i<27;i++)
		free_list(to_free->position[i]);
	free(to_free);
	return NULL;
}