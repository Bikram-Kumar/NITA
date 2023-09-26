#include <stdio.h>

int main() 
{
    // Display nums div by 7 from 10-100
    // for (int i = 10; i <= 100; i++) 
    // {
    //     if (i % 7 == 0) {
    //         printf("%d\n", i);
    //     }
    // }
    
    
    
    // Display nums div by 4 & 7 from 10-100
    // for (int i = 10; i <= 100; i++) 
    // {
    //     if ((i % 4 == 0) && (i % 7 == 0)) {
    //         printf("%d\n", i);
    //     }
    // }
    
    
    
    // Display nums div by 5 & not by 3 from 10-100
    for (int i = 10; i <= 100; i++) 
    {
        if ((i % 5 == 0) && (i % 3 != 0)) {
            printf("%d\n", i);
        }
    }
    
    
    return 0;
}