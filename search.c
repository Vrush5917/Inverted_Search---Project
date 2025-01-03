#include "inverted.h"

int search(Wlist *head, char *word) {
  if (head == NULL) {
    printf("List is Empty, search not possible\n");
    return 0;
  }

  // traverse the list
  while (head != NULL) {
    // Compare each node word with the search_word
    if (strcmp(head->word, word) == 0) {
      printf("Word %s is present in %d file/s \n", word, head->file_count);

      Ltable *temp = head->Tlink;
      while (temp != NULL) {
        printf("In file: %s %d times \n", temp->file_name, temp->word_count);
        temp = temp->table_link;
      }
      printf("\n");
      return 0;
    }
    head = head->link;
  }
  printf("Search word not found\n");
}