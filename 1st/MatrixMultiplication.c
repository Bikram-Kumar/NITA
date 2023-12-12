#include <stdio.h>


int main() {
    
    int m1, n1, m2, n2;
    printf("Enter Mat1 size (m1 n1): ");
    scanf("%d %d", &m1, &n1);
    
    printf("Enter Mat2 size (m2 n2): ");
    scanf("%d %d", &m2, &n2);
    
    int mat1[m1][n1];
    int mat2[m2][n2];
    int mat3[m1][n2];
    
    printf("\nEnter Mat1 (%d by %d):\n", m1, n1);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter Mat2 (%d by %d):\n", m2, n2);
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    printf("\nMat1 * Mat2 = \n");
                
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            mat3[i][j] = 0;
            
            for (int k = 0; k < n1; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
    
    
   
    return 0;
}

