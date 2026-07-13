#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  char name[30];
  char num[15];
  char mail[30];
} contact;

typedef struct {
  char name[30];
  short int id;
  long offset;
} idx;

typedef struct {
  long *offset_ptr;
  int count;
} off;

void initializeDatabase();
int addContact();
int listContact();
off searchIdx(char target[30]);
off searchContact();
int deleteContact();

int main() {

  initializeDatabase();
  int choice = -1;

  system("clear");
  printf("====================================================================="
         "====================================================================="
         "=====================\n");
  printf("====================================================================="
         "====================================================================="
         "=====================\n");
  printf("\t\t\t\t\t\t----||CLI Maniac Contact Book||----");

  while (choice != 0) {
    printf("\n\nHey user! What would you like to do??\n");
    printf("1. Add a contact detail to database. \n2. List all stored "
           "contact details. \n3. Search a contact. \n4. Delete a contact. "
           "\n0. Exit.\n");
    scanf("%d", &choice);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
      ;

    switch (choice) {
    case 1: {
      printf("Gotchu, starting add contact service!\n");
      if (addContact() != 0) {
        printf("Uh oh! Some error happened!");
        return 1;
      }
      printf("Contact successfully added\n");
      break;
    }
    case 2: {
      printf("Gotchu, starting list contact service!\n");
      if (listContact() != 0) {
        printf("Uh oh! Some error happened!");
        return 1;
      }
      break;
    }
    case 3: {
      printf("Gotchu, starting search contact service!\n");
      off res = searchContact();
      free(res.offset_ptr);
      if (res.count == -1) {
        printf("Some error happened!");
        return 1;
      }
      break;
    }
    case 4: {
      printf("Gotchu, starting delete contact service!\n");
      if (deleteContact() == -1) {
        printf("Some error happened!");
        return 1;
      }
      break;
    }
    case 0: {
      printf("Exiting program!\n");
      sleep(1);
      printf("================================================================="
             "===="
             "================================================================="
             "=====================\n");
      printf("================================================================="
             "===="
             "================================================================="
             "=====================\n");
      return 0;
    }
    default: {
      printf("ERROR: Invalid service");
    }
    }
    printf("\nPress ENTER to go back to main menu!\n");
    getchar();
    sleep(1);
    system("clear");
  }
  return 0;
}

void initializeDatabase() {
  FILE *fp;

  fp = fopen("data.bin", "ab");
  if (!fp) {
    perror("Failed to create data.bin");
    exit(EXIT_FAILURE);
  }
  fclose(fp);

  fp = fopen("idx.bin", "ab");
  if (!fp) {
    perror("Failed to create idx.bin");
    exit(EXIT_FAILURE);
  }
  fclose(fp);
}

int addContact() {
  FILE *fdata = fopen("data.bin", "ab");
  if (!fdata) {
    perror("Error accessing data");
    return 1;
  }
  contact person;
  printf("Enter the name of the person: ");
  fgets(person.name, 30, stdin);
  person.name[strcspn(person.name, "\n")] = 0;

  printf("Enter the contact number of the person: ");
  fgets(person.num, 15, stdin);
  person.num[strcspn(person.num, "\n")] = 0;

  printf("Enter the mail id of the person: ");
  fgets(person.mail, 30, stdin);
  person.mail[strcspn(person.mail, "\n")] = 0;

  idx personIdx;
  strcpy(personIdx.name, person.name);

  off res = searchIdx(person.name);
  FILE *fidx = fopen("idx.bin", "ab");
  if (!fidx) {
    perror("Error accessing index");
    fclose(fdata);
    return 1;
  }

  if (res.count == -1) {
    printf("Error allocating memory\n");
    return -1;
  }
  personIdx.id = 1 + res.count;
  fseek(fdata, 0, SEEK_END);
  personIdx.offset = ftell(fdata);
  printf("Offset: %ld\n", personIdx.offset);

  fwrite(&person, sizeof(contact), 1, fdata);
  fwrite(&personIdx, sizeof(idx), 1, fidx);

  free(res.offset_ptr);
  fclose(fdata);
  fclose(fidx);
  return 0;
}

int listContact() {
  FILE *fdata = fopen("data.bin", "rb");
  FILE *fidx = fopen("idx.bin", "rb");

  if (!fdata || !fidx) {
    if (fdata)
      fclose(fdata);
    if (fidx)
      fclose(fidx);
    return 1;
  }

  idx tempIdx;
  contact person;
  int i = 0;
  printf("   Name%-16s | Number%-9s | Mail%-21s\n\n", "", "", "");
  while (fread(&tempIdx, sizeof(idx), 1, fidx) == 1) {
    if (tempIdx.offset != -1) {
      fseek(fdata, tempIdx.offset, SEEK_SET);
      fread(&person, sizeof(contact), 1, fdata);
      printf("%d. %-20s | %-15s | %-25s\n", i + 1, person.name, person.num,
             person.mail);
      i++;
    }
  }

  fclose(fdata);
  fclose(fidx);
  return 0;
}

off searchIdx(char target[30]) {
  off result;
  result.offset_ptr = NULL;
  FILE *fidx = fopen("idx.bin", "rb");
  if (!fidx) {
    perror("Error accessing index");
    result.count = -1;
    return result;
  }

  result.count = 0;
  int size = 2;
  result.offset_ptr = (long *)malloc(size * sizeof(long));

  idx personIdx;
  while (fread(&personIdx, sizeof(idx), 1, fidx) == 1) {
    if (strcmp(personIdx.name, target) == 0 && personIdx.offset != -1) {
      if (result.count >= (size)) {
        (size) = (size) * 2;
        result.offset_ptr =
            (long *)realloc(result.offset_ptr, (size) * sizeof(long));
        if (!result.offset_ptr) {
          fclose(fidx);
          result.count = -1;
          return result;
        }
      }
      result.offset_ptr[result.count] = personIdx.offset;
      result.count++;
    }
  }

  fclose(fidx);
  return result;
}

off searchContact() {
  off res;
  FILE *fdata = fopen("data.bin", "rb");
  if (!fdata) {
    perror("Error accessing data");
    res.count = -1;
    return res;
  }

  char target[30];
  printf("Enter the name of the contact: ");
  fgets(target, 30, stdin);
  target[strcspn(target, "\n")] = 0;

  res = searchIdx(target);

  if (res.count == -1) {
    printf("Error allocating memory for search\n");
    res.count = -1;
    return res;
  } else if (res.count == 0) {
    printf("No matching contact found!\n");
    res.count = 0;
    return res;
  }
  contact person;

  printf("   Name%-16s | Number%-9s | Mail%-21s\n\n", "", "", "");
  for (int i = 0; i < res.count; i++) {
    fseek(fdata, res.offset_ptr[i], SEEK_SET);
    fread(&person, sizeof(contact), 1, fdata);

    printf("%d. %-20s | %-15s | %-25s\n", i + 1, person.name, person.num,
           person.mail);
  }
  fclose(fdata);
  return res;
}

int deleteContact() {
  off res = searchContact();
  if (res.count <= 0) {
    if (res.offset_ptr)
      free(res.offset_ptr);
    return -1;
  }

  int choice;
  printf("\nWhich record number to delete (1-%d)? Or 0 to cancel: ", res.count);
  scanf("%d", &choice);
  while (getchar() != '\n')
    ;

  if (choice > 0 && choice <= res.count) {
    long targetOffset = res.offset_ptr[choice - 1];

    FILE *fidx = fopen("idx.bin", "r+b"); // r+b lets you overwrite!
    if (!fidx) {
      perror("Error deleting contact");
      return -1;
    }
    idx temp;
    while (fread(&temp, sizeof(idx), 1, fidx) == 1) {
      if (temp.offset == targetOffset) {
        temp.offset = -1;                    // Mark as deleted
        fseek(fidx, -sizeof(idx), SEEK_CUR); // Move back one struct
        fwrite(&temp, sizeof(idx), 1, fidx); // Overwrite it
        printf("Deleted successfully!\n");
        break;
      }
    }
    fclose(fidx);
  }

  free(res.offset_ptr);
  return 0;
}