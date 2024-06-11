# Operator Overloading

## Key Concepts 
- Keyword `operator`
- Operator Overloading

### What is Operator Overloading?

- A generalization of function overloading
- An extension to C++ standard operators to define how they should work with user-defined types such as classes

### Why Overload Operators?
- Improves readability
- Allows for a more natural way to implement code.

### Rules and Restrictions on Operator Overloading 
- The precedence of an operator cannot be changed.
- The associativity of an operator cannot be changed, i.e., left-to-right or right-to-left.
- The "arity" of an operator cannot be changed, i.e., if the operator accepts one operand (unary) or two operands (binary).
- Only existing operators may be overloaded.

### Which Operators Cannot be Overloaded?
`.` (member access operator)
`.*` (pointer to member)
`::` (scope resolution operator)
`?:` (ternary conditional operator)

### Recall Class `ComplexNumber's` `Add()` Function
- **Definition for the `add()` Member Function**
```c++
// Prototype: ComplexNumber add (const ComplexNumber &operand);
// Definition – notice the binary scope resolution operator
ComplexNumber ComplexNumber::add(const ComplexNumber &operand)
{
    // This adds the real part of the “operand” object
    // to the real part of the object that invokes the
    // call to the function; it also adds the imaginary
    // parts
    ComplexNumber result; // Declare local ComplexNumber
    // Recall we use the dot member operator (.) to access
    // members of a class; no dot (.) denotes accessing the
    // instantiated object’s members; note we don’t have to apply “special”
    // operators to access an object passed by reference!
    result.mRealPart = mRealPart + operand.mRealPart; 
    result.mImaginaryPart = mImaginaryPart + operand.mImaginaryPart;
    // Don’t want to pass back by reference; cause undefined behavior
    return result;
}
```
### Replace `Add()` by Overloading `+` (Using a Friend Function) (1)
Overload the Binary `+` Operator.
- **This function is a non-member function but is a friend of ComplexNumber.**
```c++
// Prototype: friend ComplexNumber operator+ (const ComplexNumber &lhs, const ComplexNumber &rhs);
// Definition – notice the operator is not preceded by ComplexNumber::, because
// it’s a non-member operator. Made this function a friend of ComplexNumber
// to efficiently access the private data members of ComplexNumber.
ComplexNumber operator+ (const ComplexNumber &lhs, const ComplexNumber &rhs)
{
    ComplexNumber result; // Declare local ComplexNumber
    result.mRealPart = lhs.mRealPart + rhs.mRealPart; 
    result.mImaginaryPart = lhs.mImaginaryPart + rhs.mImaginaryPart;
    // Don’t want to pass back by reference; cause undefined behavior
    return result;
}
```
#### Replace `Add()` by Overloading `+` (without Using a Friend Function) (2)
Overload the Binary `+` Operator
- **This function is a non-member function but is NOT a friend of `ComplexNumber.`**

```c++
// Prototype: ComplexNumber operator+ (const ComplexNumber &lhs, const ComplexNumber &rhs);
// Definition – notice the operator is not preceded by ComplexNumber::, because
// it’s a non-member operator. This function is NOT a friend of ComplexNumber.
// Need to use setters/getters now!
ComplexNumber operator+ (const ComplexNumber &lhs, const ComplexNumber &rhs)
{
    ComplexNumber result; // Declare local ComplexNumber
    result.setRealPart(lhs.getRealPart() + rhs.getRealPart()); 
    result.setImaginaryPart(lhs.getImaginaryPart() + rhs.getImaginaryPart());
    // Don’t want to pass back by reference; cause undefined behavior
    return result;
}
```

### Why Non-Member Overloaded Operators?
- **Enables "symmetry" and commutativity among operators, i.e.:**
```c++
ComplexNumber operator+ (const ComplexNumber &lhs, int rhs);
ComplexNumber operator+ (int lhs, const ComplexNumber &rhs);
```
- **Important to make non-member operator+ when `lhs` is not a class! Since `lhs` is not an object in this case!**

### Complete Example with Operator Overloading
- **`ComplexNumber` Class Definition**
```c++
#include <iostream>
using namespace std;

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

    // Overloading the + operator as a friend function
    friend ComplexNumber operator+ (const ComplexNumber &lhs, const ComplexNumber &rhs);
    
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

// Overloaded + operator definition
ComplexNumber operator+ (const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber result;
    result.mRealPart = lhs.mRealPart + rhs.mRealPart;
    result.mImaginaryPart = lhs.mImaginaryPart + rhs.mImaginaryPart;
    return result;
}

int main() {
    ComplexNumber c1(2.5, 3.0);
    ComplexNumber c2(4.5, 6.0);
    ComplexNumber c3 = c1 + c2; // using overloaded + operator

    c1.print();
    c2.print();
    c3.print();

    return 0;
}
```

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(12)%20Inheritance">Part 12: Inheritance</a>
</p>



























