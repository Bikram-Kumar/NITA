#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows in matrix (m): ");
    scanf("%d", &m);
    printf("Enter number of columns in matrix (n): ");
    scanf("%d", &n);
    
    int mat1[m][n];
    int mat2[m][n];
    
    printf("Enter Matrix 1: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("Enter Matrix 2: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    printf("Matrix 1 + Matrix 2 = \n");
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}