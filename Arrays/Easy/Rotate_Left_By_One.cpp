// Left rotate the array by one
// Given an array of N integers, left rotate the array by one place.

#include <iostream>
using namespace std;
void rotate_left(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {1,3,5,7,9};
    cout << "Array : ";
    display(arr,size);
    rotate_left(arr,size);
    cout << "Rotated Array : ";
    display(arr,size);
    return 0;
}

void rotate_left(int arr[], int &size){
    if (size <= 1){
        return;
    }else{
        int temp;
        temp = arr[0];
        for (int j = 0; j < size; j++){
            arr[j] = arr[j+1];
        }
        arr[size-1] = temp;
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