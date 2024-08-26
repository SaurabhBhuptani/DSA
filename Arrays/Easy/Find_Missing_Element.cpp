// Find the missing number in an array
// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

#include <iostream>
using namespace std;
int find_missing(int arr[], int n);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {1,2,4,5,6};
    cout << "Array : ";
    display(arr,size);
    cout << "Missing Element : " << find_missing(arr,size+1);
    return 0;
}

int find_missing(int arr[], int n){
    if (n <= 1){
        return -1;
    }else{
        int xr1 = 0, xr2 = 0;
        for (int i = 0; i < n-1; i++){
            xr1 ^= arr[i];
            xr2 ^= i+1;
        }
        xr2 ^= n;
        return (xr1^xr2);
    }
}

void display(int arr[], int &size){
    if (size <= 0){
        cout << "Empty Array" << endl;
    }else{
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}