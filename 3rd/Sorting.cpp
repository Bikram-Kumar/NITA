#include <iostream>

using namespace std;



void getArr(int*,int*), printArr(int*,int*);
void bubbleSort(int*,int*);
void selectionSort(int*,int*);
void insertionSort(int*,int*);
void mergeSort(int*,int*);
void quickSort(int*,int*);
void heapSort(int*,int*);
void radixSort(int*,int*);
void countingSort(int*,int*);



int main(){
    int n;
    cout << "Enter length: ";
    cin >> n;
    int arr[n];
    
    getArr(arr,arr+n);
    
    //bubbleSort(arr, arr+n);
    
    countingSort(arr, arr+n);
    
    
    printArr(arr,arr+n);
    cout << endl;
    
    
    return 0;
}




void countingSort(int* start, int* end) {
    
    int n = end-start;
    int k = n - 1;
    int count[n];
    
    
    
    
   

}






void bubbleSort(int* start, int* end) {
    bool swapped;
    int* n = end;
    
    int temp;
    do {
        swapped = false;
        for (int* i = start; i < n; i++) {
            if ((*i) > *(i+1)) {
                temp = (*i);
                (*i) = *(i+1);
                *(i+1) = temp;
                swapped = true;
            }
        }
       n--;
        
    } while (swapped);
    
    
}











void getArr(int* start,int* end) {
    cout << "Enter elements: ";
    for (int* i = start; i < end; i++) {
        cin >> *i;
    }
}


void printArr(int* start,int* end) {
    cout << "Sorted array: ";
    for (int* i = start; i < end; i++) {
        cout << *i << " ";
    }
}