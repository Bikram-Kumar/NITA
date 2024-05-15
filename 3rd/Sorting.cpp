#include <iostream>
#include <vector>

using namespace std;


void getArr(vector<int>&,int);
void printArr(vector<int>&);
void bubbleSort(int*,int*);
void selectionSort(int*,int*);
void insertionSort(int*,int*);
void mergeSort(int*,int*);
void quickSort(int*,int*);
void heapSort(int*,int*);
void radixSort(int*,int*);
void countingSort(vector<int>&);



int main(){
    int n;
    cout << "Enter length: ";
    cin >> n;
    vector<int> arr(n);
   
    getArr(arr, n);
    
    
    //bubbleSort(&arr.front(), &arr.back());
    
    countingSort(arr);
    
    
    printArr(arr);
    cout << endl;
    
    
    return 0;
}




void countingSort(vector<int>& input) {
    
    // check negative 
    for (int i : input) {
        if (i < 0) {
            cout << endl << "Counting Sort doesn't work with negative numbers." << endl;
            return;
        }
    }
    
    int n = input.size();
    int k = *max_element(input.begin(), input.end());
    vector<int> count(k+1);
    vector<int> output(input);
    
    for (int i = 0; i < n; i++) {
        int j = input[i];
        count[j] += 1;
    }
    
    for (int i = 1; i <= k; i++) {
        count[i] += count[i-1];
    }
    
    for (int i = n-1; i >= 0; i--) {
        int j = input[i];
        count[j] -= 1;
        output[count[j]] = input[i];
    }
    
    input = output;

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


void getArr(vector<int>& arr, int n) {
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArr(vector<int>& arr) {
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
}


