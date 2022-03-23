
# StudyMaterial

# Some nice points
 ## Pointer
  * pointer and variable to which pointer is pointing should have same data type 
  * Because To acces value we have to user same data type for pointer and vairable (For Dereferencing)

# Essentials of Object oriented concepts using c++
 * Objects & Classes 
 * Operator Overloading 
 * Inheritance & Polymorphism - Virtual Functions
 * Temperature
 * OOP

# Track B
 * C++, Linux, Python(OOP) ⇾ Team Project (5 Per Group)
  * Bharath will invite to GitHub Repo
  * Incremental - SDLC, CI/CD, Analysis
  * Individual Activities
   * Quiz 
   * Submitty Task
 * Soft Skills

# Diferrence B/W C and C++
| C | C++ |
|  ---  |  ---  |
| Procedural | Procedural + OOP |
| compiler gcc | compiler g++ |
| No Data Hiding | Data Hiding (Acces Specifiers) |
| Dynamic Memory allocations(Malloc calloc) | Dynamic Memory allocations(new, delete) |
| Size of char (4bytes) | Size of char (1bytes) |
| Datatypes(Bool not included) | Datatypes(Bool included) |
| Pass by value, Pass by Address | Pass by value, Pass by Address, Pass by reference(int& B = A;) |
| Sending ⇾ Pass by value  Receiving ⇾ value, Sending ⇾ Pass by Address  Receiving ⇾ Pointer|Sending ⇾ Pass by value Receiving ⇾ value, Sending ⇾ Pass by Address Receiving ⇾ Pointer, Sending ⇾ Pass by reference Receiving ⇾ Address|
| No Default arguments | Default arguments (only at right side variable) |

### namespace ⇾ This means we can use same function names but to access functions in namespace we have to use scope resolution operator (::) (name mangling different when we use function overloading in C++)
### l-value - Memory Locatable Variables
### r-value - No Memory Location / Left side of assignment expression
### To use same function for different data types we use __ Templates __

----
## Code for SWAP
```
#include <iostream>

using namespace std;

// void swap1(int* x, int* y){ //pass by address
//  int temp = *x;
//  *x = *y;
//  *y = temp;
// }

// void swap(int& x, int& y){ // pass by reference
//  int temp = x;
//  x = y;
//  y = temp;
// }

template<typename T>
T Swap(T* A, T* B){
    T temp = * A;
    *A = *B;
    *B = temp;
    return 0;
}

int main()
{ int k = 10, l = 11, m = 10, n = 11;
    cout<<k<< " "<<l<<" \n";
    Swap(&k,&l);
    cout<<k<< " "<<l<<" \n";

    return 0;
}
```
----
## Code for Classes and Objects

### __Class__ is a user defined datatype and collection of data members and member functions, to access it we will need object (class is an encapsulation (wraping up data members and member functions into single unit) user defined datatype)
### __Object__ is an instance of a class

```
#include <iostream>
using namespace std;

// create a class
class Room {

  
public:
    double defkal(double length, double breadth, double height){
        length1 = length;
        breadth1 = breadth;
        height1 = height;
        return 0;
    }
    double calculateArea() {
        return length1 * breadth1;
    }

    double calculateVolume() {
        return length1 * breadth1 * height1;
    }
    private:
    double length1;
    double breadth1;
    double height1;
};

int main() {

    // create object of Room class
    Room room1;

    // assign values to data members
    room1.defkal(10, 20, 30);

    // calculate and display the area and volume of the room
    cout << "Area of Room =  " << room1.calculateArea() << endl;
    cout << "Volume of Room =  " << room1.calculateVolume() << endl;

    return 0;
}
```
---
| Class | Structure |
| --- | --- |
| Class are of reference type | Structs are of value types |
| Memory allocation in Heap (can be changed to stack too) | Memory allocation in stack |
| Class is generally used in large programs | Struct are used in small programs |
| Classes can contain constructor or destructor | no constructor or destructor |
| inheretance allowed | inheretance not allowed |
| Access apecifiers (__By default private__) | __only public by default__ |
| Function member of the class can be virtual or abstract | Function member of the struct cannot be virtual or abstract |
---

----
# Constructor
 * A constructor is a special type of member function
 * Constructor is automatically called when object is created
 * Constructor has same name as the class itself

# Constructor Types
 * Default Constructor
 * Parameterized Constructor
 * Copy Constructor

## Default Constructor
 * Default constructor is the constructor which doesn’t take any argument. It has no parameters.

 ```
#include <iostream>
using namespace std;

class construct
{
public:
	int a, b;

	// Default Constructor
	construct()
	{
		a = 10;
		b = 20;
	}
};

int main()
{
	// Default constructor called automatically
	// when the object is created
	construct c;
	cout << "a: " << c.a << endl
		<< "b: " << c.b;
	return 1;
}

 ```

## Parameterized Constructor
 * It is used to initialize the various data elements of different objects with different values when they are created (Can be Overloaded) .

```
#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;

public:
	// Parameterized Constructor
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}

	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};

int main()
{
	// Constructor called
	Point p1(10, 15);

	// Access values assigned by constructor
	cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();

	return 0;
}

```

## Copy Constructor
 * A copy constructor is a member function which initializes an object using another object of the same class.
```
#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int x1, int y1) { x = x1; y = y1; }

	// Copy constructor
	Point(const Point &p1) {x = p1.x; y = p1.y; }

	int getX()		 { return x; }
	int getY()		 { return y; }
};

int main()
{
	Point p1(10, 15); // Normal constructor is called here
	Point p2 = p1; // Copy constructor is called here

	// Let us access values assigned by constructors
	cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
	cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

	return 0;
}

```
# Operator Overloading
 * we can make operators to work for user defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading

 ```
 #include<iostream>
using namespace std;

class Complex {
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0) {real = r; imag = i;}
	
	// This is automatically called when '+' is used with
	// between two Complex objects
	Complex operator + (Complex const &obj) {
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print() { cout << real << " + i" << imag << '\n'; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.print();
}

 ```