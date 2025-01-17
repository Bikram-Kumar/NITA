#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <functional>
#include <chrono>
#include <iomanip>

#define NUMS_COUNT 1000


using namespace std;

void generate_data(), compare();
void sort_and_report(string filename, string label);

void bubbleSort(int* arr, int len);
void insertionSort(int* arr, int len);
void selectionSort(int* arr, int len);
void mergeSort(int* arr, int len);
void quickSort(int* arr, int len);


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

    array<pair<function<void(int*, int)>, string>, 5> algos = {
        make_pair(insertionSort, "Insertion Sort"),
        make_pair(bubbleSort, "Bubble Sort"),
        make_pair(selectionSort, "Selection Sort"),
        make_pair(quickSort, "Quick Sort"),
        make_pair(mergeSort, "Merge Sort"),
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

void mergeSort(int *arr, int len){
}

void quickSort(int *arr, int len){
}
