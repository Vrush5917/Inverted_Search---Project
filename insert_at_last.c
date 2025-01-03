#include "inverted.h"

extern char *fname;

int insert_at_last(Wlist **head, data_t *data) {
  // Create a node
  Wlist *new = malloc(sizeof(Wlist));
  if (new == NULL) {
    return FAILURE;
  }

  // Update the data fields
  new->file_count = 1;
  strcpy(new->word, data);
  new->Tlink = NULL;
  new->link = NULL;

  // Call function to update LTable
  update_link_table(&new);

  if (*head == NULL) {
    *head = new;
    return SUCCESS;
  }

  Wlist *temp = *head;
  while (temp->link != NULL) {
    temp = temp->link;
  }
  temp->link = new;
  return SUCCESS;
}

int update_link_table(Wlist **head) {
  Ltable *new = malloc(sizeof(Ltable));
  if (new == NULL) {
    return FAILURE;
  }
  new->word_count = 1;
  strcpy(new->file_name, fname);
  new->table_link = NULL;

  (*head)->Tlink = new;
  return SUCCESS;
}