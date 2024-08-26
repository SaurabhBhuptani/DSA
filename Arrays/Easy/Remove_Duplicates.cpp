// Remove duplicates in-place from sorted array
// Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

#include <iostream>
using namespace std;
void remove_duplicates(int arr[], int &size);
void deletion(int arr[], int &size, int pos);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10;
    int arr[capacity] = {2,2,3,3,5,5,5,7,7,7};
    cout << "Original Array : ";
    display(arr,size);
    remove_duplicates(arr,size);
    cout << "Array without Duplicates : ";
    display(arr,size);
    return 0;
}

void remove_duplicates(int arr[], int &size){
    if (size <= 1){
        return;
    }else{
        for (int i = 0; i < size; i++){
            if (arr[i] == arr[i+1]){
                deletion(arr,size,i+1);
                i--;
            }
        }
    }
}

void deletion(int arr[], int &size, int pos){
    if (pos < 0 || pos > size){
        cout << "Position out of bounds" << endl;
    }else{
        for (int i = pos; i < size; i++){
            arr[i] = arr[i+1];
        }
        size--;
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