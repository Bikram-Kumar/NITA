#include <stdio.h>
#include <string.h>



void p1(), p2(), p3();

struct Nums {
    int a;
    int b;
};


struct Person {
    int age;
    char name[32];
    char address[64];
};



struct Computer {
    char brand[16];
    int ram;
    int storage;
    char os[16];
};



int main () {
    p1();
    p2();
    p3();

    return 0;
}

void p1(){
    struct Nums nums;
    printf("Enter two numbers: ");
    scanf("%d %d", &nums.a, &nums.b);
    printf("%d + %d = %d\n", nums.a, nums.b, nums.a + nums.b);


}

void p2(){
    struct Person person;
    printf("Enter name: ");
    scanf(" %[^\n]", person.name);
    printf("Enter age: ");
    scanf("%d", &person.age);
    printf("Enter address: ");
    scanf(" %[^\n]", person.address);

    printf("Name: %s\nAge: %d\nAddress: %s\n", person.name, person.age, person.address);
}


void p3(){
    struct Computer computer;
    printf("Enter Brand: ");
    scanf(" %s", computer.brand);
    printf("Enter RAM (in GB): ");
    scanf("%d", &computer.ram);
    printf("Enter storage (in GB): ");
    scanf("%d", &computer.storage);
    printf("Enter OS name: ");
    scanf(" %s", computer.os);

    printf("Brand: %s\nRAM: %d\nStorage: %d\nOS: %s\n", computer.brand, computer.ram, computer.storage, computer.os);

}


