#ifndef SONG_LIST
#define SONG_LIST
struct song {
  char *name;
  char *artist;
  struct song *next;
};

// creates a song struct
struct song *new_song(char *n, char *a);

// insert fronts
struct song *insert_front(struct song *s, char *n, char *a);

// free the song struct
struct song *free_song(struct song *s);

// finds song based on name and artist. If not returns null
struct song *find_song(struct song *s, char *n, char *a);

// finds the first song of an artist
struct song *find_firstS(struct song *s, char *a);

// prints list in format [name by artist]
void print_list(struct song *s);

// returns random song
struct song *random_find(struct song *s);

// frees the link list
struct song *free_list(struct song *song);

// removes a song from within the linked list
struct song *remove_song(struct song *song, struct song *prev_song);

struct song *insert_sorted(struct song *, struct song *new_song);
#endif /* ifndef SHUX_LIST */
