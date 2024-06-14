# Quiz 7

## Questions

### Part 1: Short Answer 
#### **What is Inheritance? Explain***
**Answer:**
- Inheritance is a feature of object-oriented programming that allows a new class to inherit properties and behaviors (methods) from an existing class. The new class is called the derived (or child) class, and the existing class is called the base (or parent) class. Inheritance promotes code reuse and establishes a natural hierarchy between classes.
```c++
class Base {
public:
    void display() {
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show" << endl;
    }
};

int main() {
    Derived d;
    d.display(); // Base class method
    d.show();    // Derived class method
    return 0;
}
```

---
### Part 2: Fill-In-The-Blank

**2. The following class diagram is an example of multiple __ `inheritance` __.**

**Diagram**
```
  Shape
    ^
    |
 Retangle
    ^
    |
  Square

```

**3. Inheritance is representative of a(n) __ `IS-A` __ relationship. A Rectangle object demonstrates this relationship because it can be treated as a Shape object.**

**4. When an object of a derived class is instantiated the base class’ __ `constructor` __ is called implicitly or explicitly to initialize the data members of the base-class in the derived-class object.**

**5. __ `multilevel` __  inheritance is demonstrated when a derived class inherits properties from 2 or more base classes.**

**6. __ `Software Testing` __ provides higher levels of developer productivity through leveraging well-tested quality code.**


---

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%208">Quiz 8</a>
</p>








































