#include <iostream>
#include <functional>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #define Sleep(t) usleep((t) * 1000)
#endif


void getArr(int*,int*);
void printArr(int*,int*);
int* linearSearch(int*,int*,int);
int* binarySearch(int*,int*,int);

#define SLEEP_TIME 1000

using namespace std;

int main () {
    
    int n, num;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    getArr(arr, arr+n);
    
    cout << "Enter number to search: ";
    cin >> num;
    
    int* iptr;
    
    
    cout << "\nStarting Linear Search...\n";
    Sleep(SLEEP_TIME);
    iptr = linearSearch(arr, arr+n, num);
   
    
    if (iptr == nullptr) {
        cout << num << " not found in array" << endl;
    } else {
        cout << num << " found at index " << iptr - arr << endl;
    }
    
    cout << endl;
    Sleep(SLEEP_TIME);
    
    int sortedArr[n];
    copy(arr, arr+n, sortedArr);
    sort(sortedArr, sortedArr+n);
    
    if (!equal(arr, arr+n, sortedArr, sortedArr+n)) {
        cout << "Binary Search requires sorted array." << endl;
        
        cout << "Sorting array.";
        Sleep(SLEEP_TIME);
        cout << ".";
        flush(cout);
        Sleep(SLEEP_TIME);
        cout << ".";
        flush(cout);
        Sleep(SLEEP_TIME);
        cout << " Done";
        flush(cout);
        
        Sleep(SLEEP_TIME);
        cout << "\nSorted array: ";
        printArr(sortedArr, sortedArr+n);
        cout << endl;
        Sleep(SLEEP_TIME);
        
    }
    cout << "\nStarting Binary Search...\n";
    iptr = binarySearch(sortedArr, sortedArr+n, num);
    
    Sleep(SLEEP_TIME);
    
    if (iptr == nullptr) {
        cout << num << " not found in array" << endl;
    } else {
        cout << num << " found at index " << iptr - sortedArr << " in the sorted array" << endl;
    }
    
    
    
    return 0;
}


int* binarySearch(int* start, int* end, int num) {
    
    int* mid = start + ((end - start) / 2);
    
    cout << "Found " << *mid << endl;
    Sleep(SLEEP_TIME);
    if ((*mid) == num) return mid;
    if ((end-start) <= 1) return nullptr;
    
    if ((*mid) < num) return binarySearch(mid, end, num);
    return binarySearch(start, mid, num);

}
    
    
    
int* linearSearch(int* start, int* end, int num) {
    for (int* i = start;i < end; i++) {
        cout << "Found " << *i << endl;
        Sleep(SLEEP_TIME);
        if ((*i) == num) {
            return i;
        }
    }
    return nullptr;
}
    
void getArr(int* start, int* end) {
    cout << "Enter values: ";
    while (start < end) {
        cin >> (*start);
        start++;
    }
}


void printArr(int* start, int* end) {
    while (start < end) {
        cout << (*start) << " ";
        start++;
    }
}
