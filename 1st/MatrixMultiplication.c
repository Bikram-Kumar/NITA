#include <stdio.h>


int main() {
    
    int r1, c1, r2, c2;
    printf("Enter Mat1 size (r1 c1): ");
    scanf("%d %d", &r1, &c1);
    
    printf("Enter Mat2 size (r2 c2): ");
    scanf("%d %d", &r2, &c2);
    
    if (c1 != r2) {
        printf("Matrices with given dimensions can not be multiplied!\n");
        printf("(c1 should be equal to r2)\n");
        return 0;
    }
    
    int mat1[r1][c1];
    int mat2[r2][c2];
    int mat3[r1][c2];
    
    printf("\nEnter Mat1 (%d by %d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter Mat2 (%d by %d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    printf("\nMat1 * Mat2 = \n");
                
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            mat3[i][j] = 0;
            
            for (int k = 0; k < c1; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
    
    
   
    return 0;
}

