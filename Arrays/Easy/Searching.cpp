// Linear Search
// Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

#include <iostream>
using namespace std;
void searching(int arr[], int &size, int key);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5, key = 7;
    int arr[capacity] = {2,5,7,9,3};
    cout << "Array : ";
    display(arr,size);
    searching(arr,size,key);
    return 0;
}

void searching(int arr[], int &size, int key){
    if (size <= 0){
        return;
    }else{
        for (int i = 0; i < size; i++){
            if (arr[i] == key){
                cout << "The index of " << key << " : " << i << endl;
                return;
            }
        }
        cout << "The index of " << key << " : " << -1 << endl;
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