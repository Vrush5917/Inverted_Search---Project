#include "inverted.h"

int update_database(Flist **f_head, Wlist *head[]) {
  char file_name[FNAME_SIZE];
  printf("Enter the filename:\n");
  scanf("%s", file_name);

  int empty = isFileEmpty(file_name);
  if (empty == FILE_NOTAVAILABLE) {
    printf("File : %s is not more available\n", file_name);
    printf("Hence we are not adding the file into the file linked list\n");

  } else if (empty == FILE_EMPTY) {
    printf("File : %s is not having any content in it\n", file_name);
    printf("Hence we are not adding the file into the file linked list\n");

  } else {
    int ret = to_create_list_of_files(f_head, file_name);
    if (ret == SUCCESS) {
      printf("Successfull: inserting the file %s into the file linked list\n",
             file_name);
    } else if (ret == REPEATATION) {
      printf(
          "This file %s is repeated. Do not add that file to file linked "
          "list\n",
          file_name);
    } else {
      printf("Failure\n");
    }
  }

  while (*f_head != NULL) {
    if (strcmp((*f_head)->file_name, file_name) == 0) {
      if (create_database(f_head, head) == SUCCESS) {
        return SUCCESS;
      } else {
        return FAILURE;
      }
    }
    *f_head = (*f_head)->link;
  }
}
