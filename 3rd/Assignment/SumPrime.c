#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool binarySearch (int* arr, int n, int val) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < val) {
            left = mid + 1;
        } else if (arr[mid] > val) {
            right = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}

bool isPrime (int* primeList, int n, int num) {
    int sq = sqrt(num);
    for (int i = 0; i < n; i++) {
        if (primeList[i] > sq) break;
        if (num % primeList[i] == 0) return false;
    }
    return true;

}

int main () {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int* primeList = malloc(sizeof(int) * (n+1)/2);
    int index = 0;
    primeList[index++] = 2;

    for (int i = 3; i < n; i += 2) {
        if (isPrime(primeList, index, i)) primeList[index++] = i;
    }

    for (int i = 0; i < index; i++) {
        if (primeList[i] > n/2) break;
        if (binarySearch(primeList, index, n - primeList[i])) printf("%d + %d = %d\n", primeList[i], n-primeList[i], n);
    }
    
    free(primeList);
    return 0;
}