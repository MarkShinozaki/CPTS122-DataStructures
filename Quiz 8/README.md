# Quiz 8 - More OOP

## Questions 

### **1. What are the Four Pillars of Object-Oriented Programming (OOP)? Explain each using your own words.**
**Answer:**
- **Abstraction**: ***Abstraction involves keeping only the most important features and hiding the details. It allows users to interact with complex systems by simplifying the interface.***

- **Encapsulation**: ***Encapsulation binds data and functions that manipulate the data into a single unit (class), and restricts access to some of the object's components. This helps protect the data from unauthorized access and modification.***

- **Inheritance**: ***Inheritance is the process by which one class inherits the properties and behaviors of another class. It enables code reuse and establishes a hierarchical relationship between classes.***

- **Polymorphism**: ***Polymorphism allows objects of different classes to be treated as objects of a common super class. It enables one interface to be used for a general class of actions, with specific action determined at runtime.***

---

### **2. Given the following function, what is the worst-case Big-O time complexity?**
**Answer:**
- **The worst-case time complexity is `O(n^3).`**
```c++
// Prints all subarrays in arr[0..n-1]
void subArray(int arr[], int n) {
    // Pick starting point
    for (int i = 0; i < n; i++) {
        // Pick ending point
        for (int j = i; j < n; j++) {
            // Print subarray between current starting and ending points
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}
```

---

### **3. In regards to inheritance, what is the diamond problem? Explain.**
**Answer:**
- The diamond problem is an ambiguity that arises in multiple inheritance. It occurs when two classes B and C inherit from a common base class A, and a class D inherits from both B and C. If both B and C have overridden a method from A, and D inherits from both B and C, it is unclear which version of the method D should inherit.

---

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%209">Quiz 9</a>
</p>






