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




















