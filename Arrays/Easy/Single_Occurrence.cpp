// Find the number that appears once, and the other numbers twice
// Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include <iostream>
using namespace std;
int single_occurrence(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {3,2,4,2,4};
    cout << "Array : ";
    display(arr,size);
    cout << "Single Occurrence Element : " << single_occurrence(arr,size);
    return 0;
}

int single_occurrence(int arr[], int &size){
    if (size <= 0){
        return -1;
    }else{
        int element = 0;
        for (int i = 0; i < size; i++){
            element ^= arr[i];
        }
        return element;
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