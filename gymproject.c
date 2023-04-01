#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN + 1];
  char membership_type[MAX_NAME_LEN + 1];
  int billing_day;
  int billing_amount;
} gym_member;

gym_member members[MAX_MEMBERS];
int num_members = 0;

void register_member() {
  if (num_members == MAX_MEMBERS) {
    printf("Error: Cannot register more members.\n");
    return;
  }else{
  printf("Enter name: ");
  scanf("%s", &members[num_members].name);

  printf("Enter membership type: ");
  scanf("%s", &members[num_members].membership_type);

  printf("Enter billing day: ");
  scanf("%d", &members[num_members].billing_day);

  printf("Enter billing amount: ");
  scanf("%d", &members[num_members].billing_amount);

  num_members++;
  }

}

void schedule() {
  char member_name[MAX_NAME_LEN + 1];
  int i;

  printf("Enter member name: ");
  scanf("%s", member_name);

  for (i = 0; i < num_members; i++) {
    if (strcmp(members[i].name, member_name) == 0) {
      printf("%s is scheduled for today.\n", member_name);
      return;
    }
  }

  printf("Error: Member not found.\n");
}

void bill() {
  char member_name[MAX_NAME_LEN + 1];
  int i;

  printf("Enter member name: ");
  scanf("%s", member_name);

  for (i = 0; i < num_members; i++) {
    if (strcmp(members[i].name, member_name) == 0) {
      printf("%s has a balance of $%d.\n", member_name, members[i].billing_amount);
      return;
    }
  }

  printf("Error: Member not found.\n");
}

int main() {
  int choice;

  while (1) {
    printf("\n \nGym Management Menu:\n");
    printf("1. Register member\n");
    printf("2. Schedule\n");
    printf("3. Bill\n");
    printf("4. Quit\n");
    printf("\n \n Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        register_member();
        break;
      case 2:
        schedule();
        break;
      case 3:
        bill();
        break;
      case 4:
        return 0;
      default:
        printf("Error: Invalid choice.\n");
        break;
    }
  }

  return 0;
}

