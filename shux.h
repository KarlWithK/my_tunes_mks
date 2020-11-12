#ifndef SHUX
#define SHUX value
// LIBRARY!!!!
struct library {
  struct song *position[27];
};

// creates a new library
struct library *new_lib();

// correct adds a song struct where appropriate in the library
struct library *lib_add_song(struct library *lib, struct song *to_add);

// finds song based on name and artist. If not returns null
struct song *lib_find_song(struct library *lib, char *n, char *a);

// looks for artist in library, prints whether found or not
void lib_find_artist(struct library *lib, char *a);

// Print out all the entries under a certain letter.
void lib_print_by_letter(struct library *lib, char l);

// looks for all songs by an artist
void lib_print_by_artist(struct library *lib, char *a);

// Prints whole library
void lib_print_all(struct library *lib);

// Shuffle - print out a series of randomly chosen songs.
void lib_print_random(struct library *lib);

// Delete a song
struct library *lib_delete_song(struct library *lib, struct song *to_delete);

// Clear the library.
struct library *lib_clear_all(struct library *to_clear);

// Free the library
struct library *lib_free(struct library *to_free);
#endif /* ifndef SHUX */
