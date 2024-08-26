// Check if array is sorted
// Given an array of size n, write a program to check if the given array is sorted in (Ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, else return False.

#include <iostream>
using namespace std;
void check_if_sorted(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {1,3,5,7,9};
    cout << "Array : ";
    display(arr,size);
    check_if_sorted(arr,size);
    return 0;
}

void check_if_sorted(int arr[], int &size){
    if (size <= 1){
        cout << "Array Too Short or Empty" << endl;
    }else{
        for (int i = 1; i < size; i++){
            if (arr[i-1] > arr[i]){
                cout << "Array is Sorted : False" << endl;
            }
        }
        cout << "Array is Sorted : True" << endl;
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