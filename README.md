# StudyMaterial

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
| Datatypes(Bool not included) | Datatypes(Bool not included) |
| Pass by value, Pass by Address | Pass by value, Pass by Address, Pass by reference(int& B = A;) |
| Sending ⇾ Pass by value  Receiving ⇾ value, Sending ⇾ Pass by Address  Receiving ⇾ Pointer|Sending ⇾ Pass by value Receiving ⇾ value, Sending ⇾ Pass by Address Receiving ⇾ Pointer, Sending ⇾ Pass by reference Receiving ⇾ Address|
| No Default arguments | Default arguments (only at right side variable) |

namespace ⇾ Here we can use Same names for different codes
l-value - Memory Locatable Variables
r-value - No Memory Location / Left side of assignment expression
name mangling different when we use function overloading in C++
To use same function for different data types we use __ Templates __

----
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
```
// Program to illustrate the working of
// objects and class in C++ Programming

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
----
