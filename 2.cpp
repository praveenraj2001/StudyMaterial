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