# Quiz 3
## Questions 

### **1. What is a Constructor? Explain.**
**Answer:**
- A constructor is a special member function of a class that is executed whenever new objects of that class are created. The constructor has the same name as the class and does not have a return type. Its primary purpose is to initialize the data members of the class when an object is instantiated.

**Example:**
```c++
class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {} // Constructor
};

int main() {
    MyClass obj(10); // obj.value is initialized to 10
    return 0;
}
```

---

### **2. What is a Encapsulation? Explain.**
**Answer:**
- Encapsulation is an object-oriented programming concept that binds together the data and the functions that manipulate the data, and keeps both safe from outside interference and misuse. It restricts direct access to some of an object’s components, which can prevent the accidental modification of data. Encapsulation is typically achieved using access specifiers such as private, protected, and public.
**Example:**
```c++
class MyClass {
private:
    int data;
public:
    void setData(int d) {
        data = d;
    }
    int getData() {
        return data;
    }
};

int main() {
    MyClass obj;
    obj.setData(10);
    int val = obj.getData(); // val is 10
    return 0;
}

```
---
### **3. What is a Reference? Explain.
**Answer:**
- A reference is an alias for another variable. Once a reference is initialized to a variable, it cannot be changed to refer to another variable. References are used to pass variables to functions without copying. This allows functions to modify the variable's value directly.
**Example:**
 ```c++
void increment(int &ref) {
    ref++;
}

int main() {
    int num = 10;
    increment(num); // num becomes 11
    return 0;
}
```
---

### **4. What is a class? Explain.
**Answer:**
- A class is a user-defined data type that serves as a blueprint for creating objects. It encapsulates data and functions that operate on that data. A class can have access specifiers (private, protected, public) to control access to its members.
**Example:**
```c++
class MyClass {
public:
    int data;
    void display() {
        cout << "Data: " << data << endl;
    }
};

int main() {
    MyClass obj;
    obj.data = 10;
    obj.display(); // Output: Data: 10
    return 0;
}

```











































