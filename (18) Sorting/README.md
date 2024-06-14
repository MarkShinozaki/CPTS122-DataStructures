# Sorting in C++
## Introduction to Sorting 

Sorting is the process of arranging data in a specific order, typically in ascending or descending order. Sorting algorithms are fundamental in computer science as they improve the efficiency of other algorithms (such as search and merge algorithms) that require sorted data.

## Key Concepts 

### **Stability**

A sorting algorithm is stable if it preserves the relative order of records with equal keys (i.e., values). Stable sorting is important when the order of equal elements carries meaningful information.

### **In-place Sorting**

An in-place sorting algorithm uses only a small, constant amount of extra space for its operations. In-place sorting is efficient in terms of space complexity.

### **Time Complexity**

The time complexity of a sorting algorithm indicates the amount of time an algorithm takes to sort data as a function of the number of elements.

## Common Sorting Algorithms 

### **Bubble Sort**

Bubble Sort is a simple comparison-based algorithm. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

**Example**

```c++
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```
### **Selection Sort**

Selection Sort is an in-place comparison-based algorithm. It repeatedly selects the minimum element from the unsorted portion and swaps it with the first unsorted element.

**Example**

```c++
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```
### **Insertion Sort**

Insertion Sort is an in-place comparison-based algorithm. It builds the sorted array one element at a time by repeatedly picking the next element and inserting it into the correct position.

**Example**
```c++
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    insertionSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```

### **Merge Sort**

Merge Sort is a stable, comparison-based, divide-and-conquer algorithm. It divides the array into halves, recursively sorts each half, and then merges the sorted halves.

**Example**

```c++
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```
### **Quick Sort**

Quick Sort is an in-place, comparison-based, divide-and-conquer algorithm. It picks an element as a pivot and partitions the array around the pivot.

**Example**
```c++
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```

### Conclusion 

Sorting is a fundamental operation in computer science, and understanding different sorting algorithms helps in selecting the appropriate one for a given scenario. Each algorithm has its strengths and weaknesses in terms of time complexity, space complexity, stability, and ease of implementation. The examples above demonstrate various sorting algorithms in C++.


















--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(19)%20Algorithm%20Analysis">Part 19: Algorithm Analysis</a>
</p>
