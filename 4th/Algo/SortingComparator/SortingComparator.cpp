#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <chrono>
#include <iomanip>

#define NUMS_COUNT 100000
#define PRINT_SORTED true

using namespace std;

void generate_data(), compare();
void sort_and_report(string filename, string label);

void bubbleSort(int* arr, int len);
void insertionSort(int* arr, int len);
void selectionSort(int* arr, int len);
void quickSort(int* arr, int len);
void mergeSort(int* arr, int len);
void heapSort(int* arr, int len);
void radixSort(int* arr, int len);


// pass 'g' to generate data first then execute with 'e'
int main (int argc, char** argv) {
    if (argc > 1) {
        string op = argv[1];
        if (op == "g") {
            generate_data();
        } else if (op == "e") {
            compare();
        }
    }
    return 0;
}


void generate_data() {
    ofstream desc_data("desc_data.txt");
    ofstream asc_data("asc_data.txt");
    ofstream rand_data("rand_data.txt");

    for (int i = 0; i < NUMS_COUNT; i++) {
        desc_data << NUMS_COUNT - i - 1 << endl;
        asc_data << i << endl;
        rand_data << rand() << endl;
    }
    desc_data.close();
    asc_data.close();
    rand_data.close();
}

void compare(){
    sort_and_report("desc_data.txt", "Worst Case");
    sort_and_report("asc_data.txt", "Best Case");
    sort_and_report("rand_data.txt", "Average Case");
}

void sort_and_report(string filename, string label) {
    ifstream stream(filename);
    string buffer;
    int nums[NUMS_COUNT];
    for (int i = 0; i < NUMS_COUNT; i++){
        getline(stream, buffer);
        nums[i] = stol(buffer);
    }

    array<pair<function<void(int*, int)>, string>, 7> algos = {
        make_pair(insertionSort, "Insertion Sort"),
        make_pair(bubbleSort, "Bubble Sort"),
        make_pair(selectionSort, "Selection Sort"),
        make_pair(mergeSort, "Merge Sort"),
        make_pair(quickSort, "Quick Sort"),
        make_pair(heapSort, "Heap Sort"),
        make_pair(radixSort, "Radix Sort"),
    };

    cout << label << ":\n";

    for (auto& algo: algos) {
        int nums_dup[NUMS_COUNT];       // sort the duplicate array
        copy(begin(nums), end(nums), begin(nums_dup));

        auto t1 = chrono::high_resolution_clock::now();
        algo.first(nums_dup, NUMS_COUNT);
        auto t2 = chrono::high_resolution_clock::now();

        const chrono::duration<float> diff = t2-t1;
        cout << "\t" << algo.second << " took " << fixed << diff.count() * 1000 << " ms\n";
        if (PRINT_SORTED) {
            for (int i = 0; i < 20; i++) {
                cout << nums_dup[i] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;



}


void insertionSort(int* arr, int len) {
    
    int i = 1;
    
    while (i < len) {
        int j = i;
        while ((j > 0) && (arr[j] < arr[j-1])) {
            swap(arr[j], arr[j-1]);
            j--;
        }
        i++;
    }
    
}




void bubbleSort(int *arr, int len){
    bool swapped;
    int* n = arr+len;
    
    int temp;
    do {
        swapped = false;
        for (int* i = arr; i < n; i++) {
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




void selectionSort(int *arr, int len) {
    int end = len;
    int max;
    
    while (end--) {
        max = 0;
        for (int i = 1; i <= end; i++) {
            if (arr[max] < arr[i]) {
                max = i;
            }
        }
        if(max != end)swap(arr[max], arr[end]);
    }
}




void quickSort(int* arr, int len) {
    
    function<void(int*, int, int)> qksort;
    
    // end is exclusive 
    qksort = [&qksort] (int* v, int start, int end) {
        
        if ((end - start) <= 1) return;
        
        
        // Hoare partition scheme (more efficient)
        
        int p = v[start + ((end-start-1) / 2)]; // choose middle as pivot 
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
    
    
    qksort(arr, 0, len);
    
}





void mergeSort(int* arr, int len) {
    
    function<void(int*, int, int, int*)> msort;
    function<void(int*, int, int, int, int*)> merge;
    
    // end is exclusive 
    msort = [&msort, &merge] (int* v, int start, int end, int* v1) {
        if ((end-start) <= 1) return;
        
        int mid = (start + end) / 2;
        
        // exchange v and v1 every turn so that both are updated and need for copying v1 every update is eliminated 
        msort(v1, start, mid, v);
        msort(v1, mid, end, v);
        
        merge(v, start, mid, end, v1);
    };
    
    
    merge = [&merge] (int* v, int start, int mid, int end, int* v1) {
        
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
    
    int* arr1 = new int[len];
    copy(arr, arr+len, arr1);
    msort(arr, 0, len, arr1);
    delete arr1;
    
}



void heapSort(int* arr, int n) {
    
    function<void(int*,int)> heapify;
    function<void(int*,int,int)> siftDown;
   
    heapify = [&heapify, &siftDown] (int* a, int len) {
        int n = len/2 - 1;
        for (int i = n; i >= 0; i--) {
            siftDown(a,i,len);
        }
    };
    
    
    siftDown = [&siftDown] (int* a, int i, int end) {
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
    
    heapify(arr, n);
    
    int end = n;
    while (end > 1) {
        end--;
        swap(arr[0], arr[end]);
        siftDown(arr,0,end);
    }
    
}




void radixSort(int* arr, int len) {
        
    int max = *max_element(arr, arr+len);
    
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
