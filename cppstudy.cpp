#include <iostream>

using namespace std;

int main(){
    
    int val1 = 20;
    int val2 = 30;
    int val3 = 40;
    
    const int num = 10;
    const int *ptr1 = &val1;
    int * const ptr2 = &val2;
    const int * const ptr3 = &val3;
    
    num = 20;
    
    cout << num << endl;
    cout << ptr1 << endl;
    cout << ptr2 << endl;
    cout << ptr3 << endl;
    
}