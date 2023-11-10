#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *dbptr;
int mode;

int id;
char fname[16], lname[16];
int age;
long long mobile;
char email[32];



void prompt_mode(), write_to_file(char data[]);
void add_player(), remove_player(), retrieve_player(), update_player();


int main() {
    char data[1000];
    
    printf("\n\tWelcome to Player Management System\n\n");
    prompt_mode();
    
  
    
    
    
    
    return 0;
}

void prompt_mode() {
    printf("Please choose mode (1/2/3/4): \n1. Add Player\n2. Remove Player\n3. Retrieve Player Data\n4. Exit\n");
    scanf("%d", &mode);
    if (mode == 1) {
        add_player();
    } else if (mode == 2) {
        remove_player();
    } else if (mode == 3) {
        retrieve_player();
    } 
}




void add_player() {
    time_t t;
    srand(t);
    
    
    printf("\n\n   Add new player\n\n");
    printf("First Name: ");
    scanf("%s", fname);
    printf("Last Name: ");
    scanf("%s", lname);
    printf("Age: ");
    scanf("%d", &age);
    printf("Mobile Number: ");
    scanf("%lld", &mobile);
    printf("Email ID: ");
    scanf("%s", email);
    
    dbptr = fopen("playerdb.txt", "a");
    
    
    
    fprintf(dbptr, "\n%d %s %s %d %lld %s", rand(), fname, lname, age, mobile, email);
    
    fclose(dbptr);
    
    printf("\nPlayer Added Successfully!\n\n");
    
    prompt_mode();
}
void remove_player() {
    int id;
    printf("Enter Player ID to remove: ");
    scanf("%d", &id);
    
    printf("\nPlayer Removed Successfully!\n\n");
    prompt_mode();
}
void retrieve_player() {
    char data[1000];
    dbptr = fopen("playerdb.txt", "r");
    
    while (fscanf(dbptr, "%d %s %s %d %lld %s", &id, fname, lname, &age, &mobile, email) != EOF ) {
        printf("\nPlayer ID: %d\n\n", id);
        printf("First Name: %s\n", fname);
        printf("Last Name: %s\n", lname);
        printf("Age: %d\n", age);
        printf("Mobile Number: %lld\n", mobile);
        printf("Email ID: %s\n", email);
    }
    
    fclose(dbptr);
    printf("\n\n");
    
    
    prompt_mode();
}



