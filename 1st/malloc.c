#include <stdio.h>
#include <stdlib.h>


int main () {
    int size, *ptr;
    printf("Enter size of numbers: ");
    scanf("%d", &size);
    
    ptr = malloc(size * sizeof(int));
    if (ptr != NULL)  {
        printf("Memory allocated by malloc(). Enter %d numbers:\n", size);
        
        for (int i=0; i<size; i++) {
            scanf("%d", ptr+i);
        }
        printf("The entered numbers are: ");
        for (int i=0; i<size; i++) {
            printf("%d ", *(ptr+i));
        }
        
        
        
    } else {
        printf("Memory not allocated!\n");
    }
    
    printf("\n");
    
    return 0;
}