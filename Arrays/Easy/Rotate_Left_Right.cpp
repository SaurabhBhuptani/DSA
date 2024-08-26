// Rotate array by K elements
// Given an array of integers, rotating array of elements by k elements either left or right.

#include <iostream>
using namespace std;
int* rotate_left(int arr[], int &size, int pos);
int* rotate_right(int arr[], int &size, int pos);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5, pos = 7;
    int arr[capacity] = {1,3,5,7,9};
    int* ptr1 = rotate_left(arr,size,pos);
    int* ptr2 = rotate_right(arr,size,pos);
    cout << "Array : ";
    display(arr,size);
    cout << "Left Rotated Array : ";
    display(ptr1,size);
    cout << "Right Rotated Array : ";
    display(ptr2,size);
    delete ptr1;
    delete ptr2;
    return 0;
}

int* rotate_left(int arr[], int &size, int pos){
    if (size <= 1 || pos == size){
        return arr;
    }else{
        if (pos > size){
            pos = pos-size;
        }
        int temp;
        int* lr = new int[size];
        for (int i = 0; i < size; i++){
            lr[i] = arr[i];
        }
        for (int i = 0; i < pos; i++){
            temp = lr[0];
            for (int j = 0; j < size; j++){
                lr[j] = lr[j+1];
            }
            lr[size-1] = temp;
        }
        return lr;
    }
}

int* rotate_right(int arr[], int &size, int pos){
    if (size <= 1 || pos == size){
        return arr;
    }else{
        if (pos > size){
            pos = pos-size;
        }
        int temp;
        int* sr = new int[size];
        for (int i = 0; i < size; i++){
            sr[i] = arr[i];
        }
        for (int i = 0; i < pos; i++){
            temp = sr[size - 1];
            for (int j = size - 1; j >= 0; j--){
                sr[j] = sr[j-1];
            }
            sr[0] = temp;
        }
        return sr;
    }
}

void display(int arr[], int &size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}