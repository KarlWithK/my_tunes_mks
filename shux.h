#ifndef SHUX_LIST
#define SHUX_LIST
struct song {
  char *name;
  char *artist;
  struct song *next;
};

// creates a song struct
struct song *new_song(char *n, char *a);

// insert fronts
struct song *insert_front(struct song *s, char *n,char *a );

// free the song struct
struct song *free_song(struct song *s);

// finds song based on name and artist. If not returns null
struct song *find_song(struct song *s, char *n,char *a);

//finds the first song of an artist
struct song *find_firstS(struct song*s, char *a);

// prints list in format [name by artist]
void print_list(struct song *s);

// returns random song
struct song *random_find(struct song *s);

// frees the link list
struct song *free_list(struct song *song);

// removes a song from within the linked list
struct song *remove_song(struct song* song, struct song* prev_song);


//LIBRARY!!!!
struct library {
	struct song *position[27];
};

//creates a new library
struct library * new_lib();

//correct adds a song struct where appropriate in the library
struct library * lib_add_song(struct song * to_add);

// finds song based on name and artist. If not returns null
struct song * lib_find_song(char *n,char *a);

//looks for artist in library, returns NULL if not found, if found says that artist found char array
char * lib_find_artist(char *a);

//Print out all the entries under a certain letter.
void lib_print_by_letter(char l);

//looks for all songs by an artist
void lib_print_by_artist(char *a);

//Prints whole library
void lib_print_all(struct library * lib);

//Shuffle - print out a series of randomly chosen songs.
void lib_print_random(struct library *lib);

//Delete a song
struct library * lib_delete_song(struct song * to_delete);

//Clear the library.
struct library * lib_clear_all(struct library * to_clear);

//Free the library
struct library * lib_free(struct library * to_free);


#endif /* ifndef SHUX_LIST */
