// Move all zeros to the end of the array
// You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

#include <iostream>
using namespace std;
void move_to_end(int arr[], int &size, int element);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10, element = 0;
    int arr[capacity] = {1,0,4,0,0,4,3,7,0,9};
    cout << "Original Array : ";
    display(arr,size);
    move_to_end(arr,size,element);
    cout << "New Array : ";
    display(arr,size);
    return 0;
}

void move_to_end(int arr[], int &size, int element){
    if (size <= 1){
        return;
    }else{
        int j = 0;
        for (int i = 0; i < size; i++){
            if (arr[j] == element){
                for (int k = j; k < size; k++){
                    arr[k] = arr[k+1];
                }
                arr[size-1] = element;
            }else{
                j++;
            }
        }
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