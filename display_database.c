#include "inverted.h"

void display_database(Wlist *head[]) {
  printf("%s%15s%23s%22s%15s\n", "[index]", "[word]", "file_count",
         "File : file_name", "word_count");

  for (int i = 0; i < 27; i++) {
    if (head[i] != NULL) {
      print_word_count(head[i]);
    }
  }
}

int print_word_count(Wlist *head) {
  // Traverse through the WList and Print
  while (head != NULL) {
    printf("  %-15d%-19s%d file/s: ", tolower(head->word[0]) % 97, head->word,
           head->file_count);
    Ltable *temp = head->Tlink;
    int first = 1;
    while (temp != NULL) {
      if (first) {
        printf("%15s%15d", temp->file_name, temp->word_count);
        first = 0;
      } else {
        printf("\n");
        printf("%61s%15d", temp->file_name, temp->word_count);
      }
      temp = temp->table_link;
    }
    printf("\n");
    head = head->link;
  }
}