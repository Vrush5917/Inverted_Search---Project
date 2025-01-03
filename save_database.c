#include "inverted.h"

void save_database(Wlist *head[]) {
  char file_name[FNAME_SIZE];
  printf("Enter the file_name where you want to save the database:\n");
  scanf("%s", file_name);

  // Open the file in W mode
  FILE *fptr = fopen(file_name, "w");
  for (int i = 0; i < 27; i++) {
    if (head[i] != NULL) {
      write_databasefile(head[i], fptr);
    }
  }
}

void write_databasefile(Wlist *head, FILE *databasefile) {
  while (head != NULL) {
    fprintf(databasefile, " #[%d]\n", tolower(head->word[0]) % 97);
    fprintf(databasefile, " Word is %s: file count is: %d file/s: ", head->word,
            head->file_count);
    Ltable *temp = head->Tlink;
    int first = 1;
    while (temp != NULL) {
      if (first) {
        fprintf(databasefile, "File is: %s: Word count is %d\n",
                temp->file_name, temp->word_count);
        first = 0;
      } else {
        fprintf(databasefile, " File is: %s: Word count is %d\n",
                temp->file_name, temp->word_count);
      }
      temp = temp->table_link;
    }
    fprintf(databasefile, "\n");
    head = head->link;
  }
}