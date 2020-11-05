#ifndef SHUX_LIST
#define SHUX_LIST
struct song {
  char *name;
  char *artist;
  struct song *next;
};

struct song *new_song(char *n, char *a);

struct song *insert_front(struct song *s, char *a,char *n );

struct song *free_song(struct song *s);

struct song *find_song(struct song *s, char *a,char *n);

//finds the first song of an artist
struct song *find_firstS(struct song*s, char *a);

void print_list(struct song *s);

struct song *random_find(struct song *s);

struct song *free_list(struct song *song);

#endif /* ifndef SHUX_LIST */
