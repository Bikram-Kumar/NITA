#include <iostream>
#include <functional>
#include <vector>

using namespace std;


void getArr(vector<int>&,int);
void printArr(vector<int>&);
void bubbleSort(int*,int*);
void selectionSort(vector<int>&);
void insertionSort(int*,int*);
void mergeSort(int*,int*);
void quickSort(int*,int*);
void heapSort(vector<int>&);
void radixSort(int*,int*);
void countingSort(vector<int>&);



int main(){
    int n;
    cout << "Enter length: ";
    cin >> n;
    vector<int> arr(n);
   
    getArr(arr, n);
    
    
    //bubbleSort(&arr.front(), &arr.back());
    //countingSort(arr);
    //heapSort(arr);
    selectionSort(arr);
    
    
    
    printArr(arr);
    cout << endl;
    
    
    return 0;
}




void selectionSort(vector<int>& arr) {
    int end = arr.size();
    int max;
    
    while (end > 1) {
        end--;
        max = 0;
        for (int i = 1; i < end; i++) {
            if (arr[max] < arr[i]) {
                max = i;
            }
        }
        swap(arr[max], arr[end]);
    }
    
}
    



void heapSort(vector<int>& arr) {
    
    function<void(vector<int>&)> heapify;
    function<void(vector<int>&,int,int)> siftDown;
   
    heapify = [&heapify, &siftDown] (vector<int>& a) {
        int n = floor(a.size()/2) - 1;
        for (int i = n; i >= 0; i--) {
            siftDown(a,i,a.size());
        }
    };
    
    
    siftDown = [&siftDown] (vector<int>& a, int i, int end) {
        int largest = i, left = (2*i)+1, right = (2*i)+2;
        
        if ((left < end) && (a[left] > a[largest])) largest = left;
        
        if ((right < end) && (a[right] > a[largest])) largest = right;
        
        if (largest != i) {
            swap(a[i], a[largest]);
            siftDown(a, largest, end);
        }
    
    };
    
    
    
    // heapify the array
    // swap first and last element so that greatest goes in last
    // repeat with decreasing end boundary
    
    heapify(arr);
    
    int end = arr.size();
    while (end > 1) {
        end--;
        swap(arr[0], arr[end]);
        siftDown(arr,0,end);
    }
    
    
   
}









void countingSort(vector<int>& input) {
    
    // check negative 
    for (int i : input) {
        if (i < 0) {
            cout << endl << "Counting Sort doesn't work with negative numbers." << endl;
            exit(0);
        }
    }
    
    int n = input.size();
    int k = *max_element(input.begin(), input.end());
    vector<int> count(k+1);
    
    for (int i = 0; i < n; i++) {
        count[input[i]]++;
    }
    
    int j = 0;
    for (int i = 0; i < k+1; i++) {
        while (count[i] > 0) {
            input[j] = i;
            count[i]--;
            j++;
        }
    }
        
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


