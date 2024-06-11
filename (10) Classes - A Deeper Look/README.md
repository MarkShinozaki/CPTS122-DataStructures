# Classes - A Deeper Look

## Key Concepts
- Composition Relationship
- const Objects
- const Member Functions
- The `this` Pointer


## Composition Relationship
- A class can have objects of other classes as members - this is composition.
- Composition is also referred to as a has-a relationship (we will not distinguish between composition and aggregation at this point).
  - For example, a car has-an engine, a pencil has-an eraser, etc.

## const Objects
- Some objects need to be mutable and some do not (immutable).
  - A mutable object's attributes may be modified given different values after creation of the object.
  - An immutable object's attributes have to be set during construction and cannot be modified later.
  - Objects can be declared as immutable using the keyword `const`.

### Example
```c++
ComplexNumber c1(2.5, 3.0); // mutable
const ComplexNumber c2(4.5, 6.0); // immutable
```

## const Member Functions
- Getter/accessor functions in most cases should be declared as const member functions.
For example:
```c++
double getRealPart() const; // declaration in ComplexNumber
``` 
- A `const` member function cannot modify members of the object.
- They also cannot call functions that try to modify members of the object.
- Note: `const` objects cannot call non-const member functions!!! However, non-const objects can call const member functions.

### Example
```c++
class ComplexNumber {
public:
    double getRealPart() const;
    double getImaginaryPart() const;
    void setRealPart(double realPart);
    void setImaginaryPart(double imaginaryPart);
private:
    double mRealPart;
    double mImaginaryPart;
};

double ComplexNumber::getRealPart() const {
    return mRealPart;
}

double ComplexNumber::getImaginaryPart() const {
    return mImaginaryPart;
}

void ComplexNumber::setRealPart(double realPart) {
    mRealPart = realPart;
}

void ComplexNumber::setImaginaryPart(double imaginaryPart) {
    mImaginaryPart = imaginaryPart;
}
```

## Copy Constructors for const Objects

- A constructor where the argument is a reference to a `const` object:
```c++
ComplexNumber(const ComplexNumber &copy);
```
### Example 
```c++
const ComplexNumber c2(4.5, 6.0); // immutable
ComplexNumber c3(c2); // invokes the copy constructor with the const argument
ComplexNumber c4 = c3; // will actually invoke the copy constructor, not overloaded 
                       // assignment because we are constructing (instantiating) 
                       // an object here
```

## The `this` Pointer
- Every object has access to a pointer called `this`.
  - It stores the address of the object.
  - The pointer is not part of the object itself, but is an implicit argument (passed by the compiler) to each of the object’s non-static member functions.
  - It can be used explicitly to reference data members in order to avoid name conflicts.

### Example 1
- Let’s say we named one of the private data members of class `ComplexNumber` `realPart`:
```c++
private:
    double realPart; // of course we’ll generally name mRealPart
```
- **We want to create a setter for the `realPart`. We need to avoid ambiguous statements!**:
```c++
public:
    void setRealPart(double realPart) {
        realPart = realPart; // ambiguous statement!
        this->realPart = realPart; // use "this" explicitly instead!
    }
```

### Example 2
- **Full class example including the use of `this`**:
```c++
class ComplexNumber {
public:
    ComplexNumber(double real = 0.0, double imaginary = 0.0);
    ComplexNumber(const ComplexNumber &copy);
    ~ComplexNumber();
    
    double getRealPart() const;
    double getImaginaryPart() const;
    void setRealPart(double realPart);
    void setImaginaryPart(double imaginaryPart);
    
    ComplexNumber add(const ComplexNumber &operand) const;
    ComplexNumber sub(const ComplexNumber &operand) const;
    void print() const;
    
private:
    double mRealPart;
    double mImaginaryPart;
};

// Implementation
ComplexNumber::ComplexNumber(double real, double imaginary)
    : mRealPart(real), mImaginaryPart(imaginary) {}

ComplexNumber::ComplexNumber(const ComplexNumber &copy)
    : mRealPart(copy.mRealPart), mImaginaryPart(copy.mImaginaryPart) {}

ComplexNumber::~ComplexNumber() {}

double ComplexNumber::getRealPart() const {
    return mRealPart;
}

double ComplexNumber::getImaginaryPart() const {
    return mImaginaryPart;
}

void ComplexNumber::setRealPart(double realPart) {
    this->mRealPart = realPart;
}

void ComplexNumber::setImaginaryPart(double imaginaryPart) {
    this->mImaginaryPart = imaginaryPart;
}

ComplexNumber ComplexNumber::add(const ComplexNumber &operand) const {
    return ComplexNumber(this->mRealPart + operand.mRealPart,
                         this->mImaginaryPart + operand.mImaginaryPart);
}

ComplexNumber ComplexNumber::sub(const ComplexNumber &operand) const {
    return ComplexNumber(this->mRealPart - operand.mRealPart,
                         this->mImaginaryPart - operand.mImaginaryPart);
}

void ComplexNumber::print() const {
    cout << mRealPart << " + " << mImaginaryPart << "i" << endl;
}

int main() {
    ComplexNumber c1(2.5, 3.0);
    const ComplexNumber c2(4.5, 6.0);
    ComplexNumber c3(c2); // invokes copy constructor
    ComplexNumber c4 = c3; // invokes copy constructor

    c1.setRealPart(5.0);
    c1.setImaginaryPart(7.0);
    c1.print();

    c3.print();
    c4.print();

    return 0;
}
```
## Type of `this` Pointer
- The type is dependent on the type of object.
  - For a non-const member function of `ComplexNumber`, the `this` pointer type would be `ComplexNumber`.
  - For a const member function, the this pointer type would be const ComplexNumber*, meaning it could not be used to modify members of the object.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(11)%20Operator%20Overloading">Part 11: Operator Overloading</a>
</p>









