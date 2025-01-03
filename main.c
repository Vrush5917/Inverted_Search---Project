#include "inverted.h"

int main(int argc, char **argv) {
  system("clear");  // To get the clear screen

  Wlist *head[27] = {NULL};
  if (argc <= 1) {
    printf("Enter the valid no of args\n");
    printf("/Slist.exe file1.txt file2txt\n");
    return 0;
  }

  // Create file linked list

  Flist *f_head = NULL;
  file_validation_n_file_list(&f_head, argv);

  char opt;
  do {
    printf("Select your choice among the following options: \n");
    printf("1.Create DATABASE\n");
    printf("2.Display DATABASE\n");
    printf("3.Update DATABASE\n");
    printf("4.Search\n");
    printf("5.Save DATABASE\n");
    int choice;
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        if (create_database(&f_head, head) == SUCCESS) {
          printf("Successfully created the database for ");
          for (int i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
          }
          printf("\n");

        } else {
          printf("Failed to create the database\n");
        }
      } break;

      case 2: {
        display_database(head);
      } break;

      case 3: {
        if (update_database(&f_head, head) == SUCCESS) {
          printf("Successfully updated the database\n");
        } else {
          printf("Failed to update the database\n");
        }
      } break;

      case 4: {
        char word[WORD_SIZE];
        printf("Enter the word:\n");
        scanf("%s", word);

        int index = tolower(word[0]) % 97;
        search(head[index], word);
      } break;

      case 5: {
        save_database(head);
      } break;
    }
    printf("Do you want to continue\n");
    printf("Enter Y/y to continue or N/n to exit\n");
    getchar();
    scanf("%c", &opt);

  } while (opt == 'Y' || opt == 'y');
}