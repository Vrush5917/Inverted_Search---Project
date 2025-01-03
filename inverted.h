#define INVERTED_SEARCH_H

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// defining macros
#define FAILURE -1
#define SUCCESS 0
#define FNAME_SIZE 15
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

typedef char data_t;

typedef struct file_node {
  data_t file_name[FNAME_SIZE];
  struct file_node *link;
} Flist;

typedef struct linkTable_node {
  int word_count;
  char file_name[FNAME_SIZE];
  struct linkTable_node *table_link;
} Ltable;

typedef struct word_node {
  int file_count;
  char word[WORD_SIZE];
  Ltable *Tlink;
  struct word_node *link;
} Wlist;

int to_create_list_of_files(Flist **f_head, char *name);

void file_validation_n_file_list(Flist **f_head, char **argv);

int isFileEmpty(char *file_name);

int create_database(Flist **f_head, Wlist *head[]);

Wlist *read_datafile(Flist *file, Wlist *head[], char *file_name);

int insert_at_last(Wlist **head, data_t *data);

int update_link_table(Wlist **head);

int update_word_count(Wlist **head, char *file_name);

void display_database(Wlist *head[]);

int print_word_count(Wlist *head);

int update_database(Flist **f_head, Wlist *head[]);

int search(Wlist *head, char *word);

void save_database(Wlist *head[]);

void write_databasefile(Wlist *head, FILE *databasefile);