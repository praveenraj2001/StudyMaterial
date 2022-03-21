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