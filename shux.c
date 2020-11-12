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
  int correct = a[0];
  if (correct > 90)
    correct -= 32;
  correct = (correct < 65 || correct > 90) ? 26 : correct - 65;
  if (lib->position[correct]) {
    return find_song(lib->position[correct], n , a);
  }
  return NULL;
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

void lib_print_random(struct library *lib) {
	struct song * rando;
	int first=1;
	int skip=1;
	for (int i = 0; i < 27; i++){
		if(first&&lib->position[i]){
			rando=new_song(lib->position[i]->name,lib->position[i]->artist);
			first=0;
		}
		if(rando){
			struct song * temp=lib->position[i];
			while(temp){
				if(!skip)
					rando=insert_front(rando, temp->name, temp->artist);
				else
					skip=0;
				temp=temp->next;
			}
		}
	}
	printf("Whole List:\n");
	print_list(rando);
	int len=0;
	struct song * rando2=rando;
	while(rando2){
		rando2=rando2->next;
		len++;
	}
	printf("Len:%d\n",len);
	int * shuffle=malloc(len*sizeof(int));
	for(int j=0;j<len;j++){
		shuffle[j]=j;
	}

	/*
	for(int j=0;j<len;j++){
		printf("j:%d\n",j);
		printf("%d\n",shuffle[j]);
		printf("\n");
	}
	*/
	
	for(int j=0;j<len;j++){
		srand(time(NULL));
		int rand_shuffle=rand()%(len-j);
		int temp=shuffle[j];
		shuffle[j]=shuffle[j+rand_shuffle];
		shuffle[j+rand_shuffle]=temp;
	}
	printf(shuffle);
	printf("\n");
	
	for(int j=0;j<len;j++){
		printf("%d\n",shuffle[j]);
		printf("\n");
	}
	
	
	/*
  struct song *rando;
  srand(time(NULL));
  for (int j = 0; j < 27; j++) {
    int i = rand()%27;
     printf("%i\n", i); 
    if (lib->position[i]) {
      struct song *temp = random_find(lib->position[i]);
      rando = insert_sorted(lib->position[i], temp); 
      rando = insert_front(lib->position[i], temp->name, temp->artist);
    }
  }
  if (!rando)
		printf("Song list was empty\n");
  else
    print_list(rando);
	*\
	/* int len=0; */
	/* struct song * s=lib->position[i]; */
	/* while (s){ */
	/* 	s=s->next; */
	/* 	len++; */
	/* } */
	/* if(len){ */
	/* 	int len2=len; */
	/* 	struct song * s=lib->position[i]; */
	/* 	int j=rand()%len; */
	/* 	while(len2){ */
	/* 		s=s->next; */
	/* 		len2--; */
	/* 	} */
	/* 	printf("%s by %s, ", s->name, s->artist); */
	/* } */
	/* else */
	/* 	printf("Song list was empty\n"); */
}

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
