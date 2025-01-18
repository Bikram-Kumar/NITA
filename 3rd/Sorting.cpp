#include <iostream>
#include <functional>
#include <vector>

using namespace std;


void getArr(vector<int>&,int);
void printArr(vector<int>&);
void checkNegative(vector<int>&,string);

void bubbleSort(int*,int*);
void selectionSort(vector<int>&);
void insertionSort(vector<int>&);
void mergeSort(vector<int>&);
void quickSortLomuto(vector<int>&);
void quickSortHoare(vector<int>&);
void heapSort(vector<int>&);
void radixSort(vector<int>&);
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
    // insertionSort(arr);
    //radixSort(arr);
    //mergeSort(arr);
    
    //quickSortLomuto(arr);
    // quickSortHoare(arr);
    
    printArr(arr);
   
    
    
    return 0;
}










void quickSortLomuto(vector<int>& arr) {
    
    function<void(vector<int>&, int, int)> qksort;
    
    // end is exclusive 
    qksort = [&qksort] (vector<int>& v, int start, int end) {
        
        if ((end - start) <= 1) return;
        
        
        
        // Lomuto partition scheme
              
        
        int pivotPos = end - 1;
        
        int i = start; 
        
        // scan through each element from start and place the smaller values than pivot first
        for (int j = start; j < pivotPos; j++) {
            if (v[j] < v[pivotPos]) {
                swap(v[j], v[i]);
                i++;
            }
        }
        // start to i-1 are less than pivot
        swap(v[i], v[pivotPos]);
        
        
        qksort(v, start, i);
        qksort(v, i+1, end); // exclude the pivot since it's already in its final position 
        
    
    };
    
    
    qksort(arr, 0, arr.size());
    
}



void quickSortHoare(vector<int>& arr) {
    
    function<void(vector<int>&, int, int)> qksort;
    
    // end is exclusive 
    qksort = [&qksort] (vector<int>& v, int start, int end) {
        
        if ((end - start) <= 1) return;
        
        
        // Hoare partition scheme (more efficient)
        
        int p = v[start]; // choose first as pivot 
        int i = start-1;
        int j = end;
        
        while (true) {
            
            do { i++; } while (v[i] < p);
            
            do { j--;} while (v[j] > p);
            
            if (i >= j) break;
            
            swap(v[i],v[j]);
            
        }
        
        qksort(v, start, j+1); // include pivot for sorting too
        qksort(v, j+1, end);
        
    
    };
    
    
    qksort(arr, 0, arr.size());
    
}







void mergeSort(vector<int>& arr) {
    
    function<void(vector<int>&, int, int, vector<int>&)> msort;
    function<void(vector<int>&, int, int, int, vector<int>&)> merge;
    
    // end is exclusive 
    msort = [&msort, &merge] (vector<int>& v, int start, int end, vector<int>& v1) {
        if ((end-start) <= 1) return;
        
        int mid = (start + end) / 2;
        
        // exchange v and v1 every turn so that both are updated and need for copying v1 every update is eliminated 
        msort(v1, start, mid, v);
        msort(v1, mid, end, v);
        
        merge(v, start, mid, end, v1);
    };
    
    
    merge = [&merge] (vector<int>& v, int start, int mid, int end, vector<int>& v1) {
        
        int j = start, k = mid;
        
        for (int i = start; i < end; i++) {
            if ((j < mid) && ((k >= end) || (v1[j] <= v1[k]))) {
                v[i] = v1[j];
                j++;
            } else {
                v[i] = v1[k];
                k++;
            }
        }
        
    };
    
    
    // arr1 is used for comparison while merging as data is updated 
    
    vector<int> arr1(arr);
    msort(arr, 0, arr.size(), arr1);
    
    
}





void radixSort(vector<int>& arr) {
    
    checkNegative(arr, "Radix");
    
    int max = *max_element(arr.begin(), arr.end());
    int len = arr.size();
    
    int p = 1, d;
    vector<int> radixArr[10] = {*(new vector<int>())};
    
    while ((max / p) > 0) {
        for (int i = 0; i < len; i++) {
            d = (arr[i] % (p * 10)) / p;
            radixArr[d].push_back(arr[i]);
        }
        int i = 0;
        
        
        for (vector<int>& v : radixArr) {
            for (int& j : v) {
                arr[i] = j;
                i++;
            }
            v.clear();
        }
        
        
        p *= 10;
    
    }
    
}




void insertionSort(vector<int>& arr) {
    
    int i = 1, len = arr.size();
    
    while (i < len) {
        int j = i;
        while ((j > 0) && (arr[j] < arr[j-1])) {
            swap(arr[j], arr[j-1]);
            j--;
        }
        i++;
    }
    
}



void selectionSort(vector<int>& arr) {
    int end = arr.size();
    int max;
    
    while (end--) {
        max = 0;
        for (int i = 1; i <= end; i++) {
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
        int n = a.size()/2 - 1;
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
    
    checkNegative(input, "Counting");
    
    
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





void checkNegative(vector<int>& arr, string name) {
    
    for (int i : arr) {
        if (i < 0) {
            cout << endl << name << " Sort doesn't work with negative numbers.\n\n";
            exit(0);
        }
    }
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
    cout << endl;
}


