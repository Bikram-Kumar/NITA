#include <stdio.h>
#include <stdlib.h>


#ifdef __INTELLISENSE__
  #pragma diag_suppress 28
#endif


void p1(), p2(), p3();

int main (){

    p1();
    // p2();
    // p3();
    return 0;
}

struct Movie {
    char name[32];
    int release_year;
    char genre[32];
};

// Implement a struct Movie. Accept data about movies using pointer to struct
void p1(){
    struct Movie movie;
    struct Movie* movie_ptr = &movie;

    printf("Enter movie name: ");
    scanf(" %[^\n]", movie_ptr->name);
    printf("Enter release year: ");
    scanf("%d", &movie_ptr->release_year);
    printf("Enter genre: ");
    scanf(" %[^\n]", movie_ptr->genre);

    printf("Name: %s\nRelease Year: %d\nGenre: %s\n", movie_ptr->name, movie_ptr->release_year, movie_ptr->genre);

}

struct MobilePhone {
    char brand[16];
    int ram;
    int storage;
};


// Implement a struct MobilePhone. Collect data using dynamic memory allocation
void p2(){
    struct MobilePhone* mobile = malloc(sizeof(struct MobilePhone));

    printf("Enter Brand: ");
    scanf(" %s", mobile->brand);
    printf("Enter RAM (in GB): ");
    scanf("%d", &mobile->ram);
    printf("Enter storage (in GB): ");
    scanf("%d", &mobile->storage);
    

    printf("Brand: %s\nRAM: %d\nStorage: %d\n", mobile->brand, mobile->ram, mobile->storage);

    free(mobile);
}


struct Employee {
    char name[32];
    int age;
    char role[32];
};

// Create a struct Employee. Accept data about n employees using array of struct
void p3(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Employee %d details\n", i);
        printf("Enter name: ");
        scanf(" %[^\n]", employees[i].name);
        printf("Enter age: ");
        scanf("%d", &employees[i].age);
        printf("Enter role: ");
        scanf(" %[^\n]", employees[i].role);

    }

    printf("Employee details:\nS.No.\tName\t\tAge\tRole\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%s\n", i, employees[i].name, employees[i].age, employees[i].role);
    }


}
