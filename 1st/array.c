#include <stdio.h>


int main() {
    
    // Program to collect 5 subject marks and display it
    /*
    int marks[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter subject %d marks: ", i + 1);
        scanf("%d", &marks[i]);
    }
    
    printf("The entered marks are: \n");
    for (int i = 0; i< 5; i++) {
        printf("Subject %d: %d\n", i+1, marks[i]);
    }
    */
    
    
    // Program to take 5 values from the user and store them in an array and display int
    /*
    int values[5];
    for (int i = 0; i<5; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &values[i]);
    }
    
    printf("The entered values are: \n");
    
    for (int i = 0; i<5; i++) {
        printf("Entry %d: %d\n", i+1, values[i]);
    }
    */
    // Program to find the average of n numbers using array
    
    int n, sum = 0;
    float average;
    
    printf("Enter n: ");
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i<n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    
    average = (float) sum / n;
    
    printf("The average of the given %d numbers is %.2f\n", n, average);
    
    
    
    return 0; 
}