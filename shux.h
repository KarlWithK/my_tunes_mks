#ifndef SHUX_LIST
#define SHUX_LIST
struct song {
  char *name;
  char *artist;
  struct song *next;
};
#endif /* ifndef SHUX_LIST */
