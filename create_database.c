#include "inverted.h"

char* fname;
int flag = 1;

int create_database(Flist** f_head, Wlist* head[]) {
  // Traverse through file linked list

  while (*f_head != NULL) {
    read_datafile(*f_head, head, (*f_head)->file_name);
    *f_head = (*f_head)->link;
  }
  return SUCCESS;
}

// Read the contents of the particular file
Wlist* read_datafile(Flist* file, Wlist* head[], char* file_name) {
  fname = file_name;
  char word[25];

  // Open the file in read mode
  FILE* fptr = fopen(file_name, "r");
  if (fptr == NULL) {
    printf("FIle is not present in the present working directory\n");
    return NULL;
  }

  while (fscanf(fptr, "%s", word) != EOF) {
    // Find the index
    int index = tolower(word[0]) % 97;
    if (index < 0 || index > 25) {
      index = 26;
    }

    // Reset flag for each new word
    flag = 1;

    // Check if words are repeated
    if (head[index] != NULL) {
      Wlist* temp = head[index];
      while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
          update_word_count(&temp, file_name);
          flag = 0;
          break;
        }
        temp = temp->link;
      }
    }

    // If the word is not found, insert it
    if (flag == 1) {
      insert_at_last(&head[index], word);
    }
  }
  fclose(fptr);
  return NULL;
}

int update_word_count(Wlist** head, char* file_name) {
  Ltable* temp = (*head)->Tlink;
  while (temp != NULL) {
    if (strcmp(temp->file_name, file_name) == 0) {
      temp->word_count++;
      return SUCCESS;
    }
    temp = temp->table_link;
  }

  // Create a new entry if the file is not found
  Ltable* new = malloc(sizeof(Ltable));
  if (new == NULL) {
    return FAILURE;
  }
  strcpy(new->file_name, file_name);
  new->word_count = 1;
  new->table_link = (*head)->Tlink;

  (*head)->Tlink = new;
  (*head)->file_count++;

  return SUCCESS;
}