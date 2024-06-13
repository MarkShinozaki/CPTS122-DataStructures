# Algorithm Analysis
## Efficiency of Algorithms 
### Analysis of Algorithms (1) 
- In general, we want to:
  - Determine the central unit of work by considering the operations applied in the algorithm.
  - Express the unit of work as a function of the size of input data: How quickly does the amount of work grow as the size of the input grows?
  - Classify algorithms according to how thier running time and/or space requirements grow as input size grows.
 
### Example: Sequential Search Algorithm 

- **Input**: List of `n` names to search, and target name to search for.
- **Method**:
1. Examine each name in sequence.
2. If all names have been examined, set found to false and stop.
3. If name equals target, set found to true and stop.
4. If name not equal to target, advance to next name.

- **Main Unit of Work**: Comparisons.
 **Analysis**:
- Best case: One comparison must be made (target is first item in list).
- Worst case: `n` comparisons must be made (target not found; all items examined).
- Average case: `n/2` comparisons must be made.
  
#### Analysis of Algorithms (2)
**Order of Magnitude ("Big-O")**
- Any algorithm whose work can be expressed as `c` * n where `c` is a constant and ``n is the input size is said to be "order of magnitude `n`", or `O(n)`.
- Likewise, any algorithm whose work varies as a constant times the square of the input size is said to be "order of magnitude `n` squared", or `O(n^2)`.

#### Analysis of Algorithms (3)
**Big-O Analysis of Sequential Search**
- Best case: `O(1)`
- Worst case: `O(n)`
- Average case: `O(n/2) = O(n)`

#### Analysis of Algorithms (4)
**Recall Selection Sort**
- **Input**: A list of numbers.
- **Output**: A list of the same numbers in ascending order.
- **Method**:
1. Set marker that divides "unsorted" and "sorted" sections of the list to the end of the list.
2. While the unsorted section of the list is not empty:
  - Find the largest value in the "unsorted" section of the list.
  - Swap with the last value in the "unsorted" section of the list.
  - Move marker left one position.

#### Analysis of Algorithms (5)
**Selection Sort (cont.)**
**Big-O Analysis**
- Units of work: Comparisons and exchanges.
- In all cases, we need n + (n-1) + ... + 1 comparisons = [n * (n-1)]/2 comparisons = 1/2n^2 - 1/2n comparisons = O(n^2) comparisons.
- In the best case, items are already in order, so 0 exchanges are needed: O(n^2) comparisons + 0 exchanges = O(n^2).
- In the worst case, items are in reverse order, so n exchanges are needed: O(n^2) comparisons + n exchanges = O(n^2).

#### Analysis of Algorithms (6)
**Selection Sort (cont.)**
**Space Analysis**
- Major space requirement is the list of numbers (`n`).
- Other space requirements:
  - Extra memory location needed for a marker between sorted and unsorted list.
  - Extra memory location needed to store `LargestSoFar` used to find the largest item in the unsorted list.
  - Extra memory location needed to exchange two values.
- Overall, space requirement is proportional to `n`.

#### Analysis of Algorithms (7)
**Recall Binary Search**
- **Input**: A list of `n` sorted values and a target value.
- **Output**: True if the target value exists in the list and the location of the target value, false otherwise.
- **Method**:
1. Set `startIndex` to 1 and `endIndex` to `n`.
2. Set `found` to false.
3. While `found` is false and `startIndex` is less than or equal to `endIndex`:
- Set `mid` to the midpoint between `startIndex` and `endIndex`.
- If target = item at `mid`, then set `found` to true.
- If target < item at `mid`, then set `endIndex` to `mid - 1`.
- If target > item at `mid`, then set `startIndex` to `mid + 1`.
4. If `found` is true, then print "Target found at location mid".
5. Else, print "Sorry, target value could not be found."

#### Analysis of Algorithms (8)
**Binary Search (cont.)**
**Big-O Analysis**
- Unit of work: Comparisons.
- Best case: Target value is at the first midpoint: `O(1)` comparisons.
- Worst case: Target value is not found. The list is cut in half until it is reduced to a list of size 0 (`startIndex` is greater than or equal to `endIndex`). The number of times a number n is divisible by another number `m` is defined to be the logb(a), so the answer is `log2(n) = O(log n)`.

#### Analysis of Algorithms (9)
**Summary of Orders of Magnitude**
- `O(log n)` = flying
- `O(n)` = driving
- `O(n^2)` = walking
- `O(n^3)` = crawling
- `O(n^4)` = barely moving
- `O(n^5)` = no visible progress
- `O(2^n)` = forget it, it will never happen

#### Example Code
**Sequential Search**
```c++
#include <iostream>
#include <vector>
using namespace std;

bool sequentialSearch(const vector<int>& data, int target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> data = {1, 2, 3, 4, 5};
    int target = 3;
    if (sequentialSearch(data, target)) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}
```
**Selection Sort**
```c++
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& data) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < data.size(); ++j) {
            if (data[j] > data[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(data[i], data[maxIndex]);
    }
}

int main() {
    vector<int> data = {3, 1, 4, 1, 5, 9};
    selectionSort(data);
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```
**Binary Search**
```c++
#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(const vector<int>& data, int target) {
    int startIndex = 0;
    int endIndex = data.size() - 1;
    
    while (startIndex <= endIndex) {
        int mid = startIndex + (endIndex - startIndex) / 2;
        if (data[mid] == target) {
            return true;
        } else if (data[mid] < target) {
            startIndex = mid + 1;
        } else {
            endIndex = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    if (binarySearch(data, target)) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}
```
--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(1)%20Introduction">Part 1: Introduction</a>
</p>
