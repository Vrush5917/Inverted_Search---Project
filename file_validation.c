#include "inverted.h"

void file_validation_n_file_list(Flist **f_head, char **argv) {
  int i = 1, empty;
  while (argv[i] != NULL) {
    empty = isFileEmpty(argv[i]);
    if (empty == FILE_NOTAVAILABLE) {
      printf("File : %s is not more available\n", argv[i]);
      printf("Hence we are not adding the file into the file linked list\n");
      i++;
      continue;
    } else if (empty == FILE_EMPTY) {
      printf("File : %s is not having any content in it\n", argv[i]);
      printf("Hence we are not adding the file into the file linked list\n");
      i++;
      continue;
    } else {
      int ret = to_create_list_of_files(f_head, argv[i]);
      if (ret == SUCCESS) {
        printf("Successfull: inserting the file %s into the file linked list\n",
               argv[i]);
      } else if (ret == REPEATATION) {
        printf(
            "This file %s is repeated. Do not add that file to file linked "
            "list\n",
            argv[i]);
      } else {
        printf("Failure\n");
      }
      i++;
      continue;
    }
  }
}

// This function is called for checking the file availability and for the file
// content
int isFileEmpty(char *file_name) {
  FILE *fptr = fopen(file_name, "r");
  if (fptr == NULL) {
    if (errno == ENOENT) {
      return FILE_NOTAVAILABLE;
    }
  }
  fseek(fptr, 0, SEEK_END);
  if (ftell(fptr) == 0) {
    fclose(fptr);
    return FILE_EMPTY;
  }
  fclose(fptr);
}

int to_create_list_of_files(Flist **f_head, char *name) {
  Flist *new = malloc(sizeof(Flist));
  if (new == NULL) {
    printf("Memory not allocated\n");
    return FAILURE;
  }
  strcpy(new->file_name, name);
  new->link = NULL;

  if (*f_head == NULL) {
    *f_head = new;
    return SUCCESS;
  }

  Flist *temp = *f_head;
  while (temp->link != NULL) {
    if (strcmp(temp->file_name, name) == 0) {
      free(new);
      return REPEATATION;
    }
    temp = temp->link;
  }

  if (strcmp(temp->file_name, name) == 0) {
    free(new);
    return REPEATATION;
  }
  temp->link = new;

  return SUCCESS;
}