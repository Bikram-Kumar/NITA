#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *dbptr;
int mode;

int id;
char tag[32]; 
char fname[16], lname[16];
int age;
long long mobile;
char email[32];



void prompt_mode();
void add_player(), retrieve_player();
void print_border();

int main() {
    char data[1000];
    print_border();
    printf("\tWelcome to Player Management System");
    print_border();
    
    prompt_mode();
    
  
    
    
    
    
    return 0;
}



void prompt_mode() {
    
    printf("Select mode: \n1. Add Player\n2. Retrieve Player Data\n3. Exit\n(1/2/3)? ");
    scanf("%d", &mode);
    if (mode == 1) {
        add_player();
    } else if (mode == 2) {
        retrieve_player();
    } 
}




void add_player() {
    time_t t;
    srand((unsigned)time(&t));
    
    print_border();
    
    printf("Add new Player\n\n");
    
    printf("Gamer Tag: ");
    scanf("%s", tag);
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
    
    id = rand();
    
    fprintf(dbptr, "\n%d %s %s %s %d %lld %s", id, tag, fname, lname, age, mobile, email);
    
    fclose(dbptr);
    
    print_border();
    
    printf("Player Added Successfully!\n\n");
    printf("%s's ID is %d", tag, id);
    
    print_border();
    
    prompt_mode();
}



void retrieve_player() {
    int retrieval_id, retrieve_mode, data_printed = 0;
    
    print_border();
    printf("1. Get Player by ID\n2. Get all Players\n(1/2)? ");
    scanf("%d", &retrieve_mode);
    
    if (retrieve_mode == 1) {
        print_border();
        printf("Enter Player ID: ");
        scanf("%d", &retrieval_id);
    }
    
    print_border();
    
    
    dbptr = fopen("playerdb.txt", "r");
    
    while (fscanf(dbptr, "%d %s %s %s %d %lld %s", &id, tag, fname, lname, &age, &mobile, email) != EOF ) {
        
        if ((retrieve_mode == 1) && (retrieval_id != id)) continue;
        
        printf("Player ID: %d\n\n", id);
        printf("Gamer Tag: %s\n", tag);
        printf("First Name: %s\n", fname);
        printf("Last Name: %s\n", lname);
        printf("Age: %d\n", age);
        printf("Mobile Number: %lld\n", mobile);
        printf("Email ID: %s\n", email);
        
        print_border();
        
        data_printed = 1;
    }
    
    fclose(dbptr);
    
    
    if (!data_printed) {
        printf("Player not found!");
    } else {
        printf("Task done successfully!");
    }
    
    
    
    print_border();
    
    prompt_mode();
}

void print_border() {
    printf("\n\n-------------------------------------------------\n\n");
}


