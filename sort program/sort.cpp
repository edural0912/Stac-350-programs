#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

//bubble sort

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

//merge sort functions 
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
//prints arr so it uses the same everytime
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arrSmall[100], arrLarge[100000];

    // Generate random integers for the arrays
    for (int i = 0; i < 100; i++) {
        arrSmall[i] = rand();
    }
    for (int i = 0; i < 100000; i++) {
        arrLarge[i] = rand();
    }

    // Measure the execution time of bubble sort for 100 integers
    auto start1 = high_resolution_clock::now();
    bubbleSort(arrSmall, 100);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "Bubble Sort Small (100): " << "elasped time in nanoseconds: " <<  duration1.count() << " ns" << endl;

    // Measure the execution time of bubble sort for 1000 integers
    auto start2 = high_resolution_clock::now();
    bubbleSort(arrLarge, 100000);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Bubble Sort Large (100000): " << "elasped time in nanoseconds: " <<  duration2.count() << " ns" << endl;

    // Measure the execution time of merge sort for 100 integers
    auto start3 = high_resolution_clock::now();
    mergeSort(arrSmall, 0, 99);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
    cout << "Merge Sort Small (100): " << "elasped time in nanoseconds: " <<  duration3.count() << " ns" << endl;

    // Measure the execution time of merge sort for 100000 integers
    auto start4 = high_resolution_clock::now();
    mergeSort(arrLarge, 0, 99999);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
    cout << "Merge Sort Large (100000): " << "elasped time in nanoseconds: " << duration4.count() << " ns" << endl;

    // Measure the execution time of the built-in sort algorithm for 100 integers
    auto start5 = high_resolution_clock::now();
    sort(arrSmall, arrSmall + 100);
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<nanoseconds>(stop5 - start5);
    cout << "Built-in Sort Small (100): " << "elasped time in nanoseconds: " << duration5.count() << " ns" << endl;

    // Measure the execution time of the built-in sort algorithm for 100000 integers
    auto start6 = high_resolution_clock::now();
    sort(arrLarge, arrLarge + 100000);
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<nanoseconds>(stop6 - start6);
    cout << "Built-in Sort Large (100000): " << "elasped time in nanoseconds: " << duration6.count() << " ns" << endl;

    return 0;
}

