// Find the majority element that occurs more than N/2 times
// Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

#include <iostream>
using namespace std;
int majority_element(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {1,3,1,3,3};
    cout << "Array : ";
    display(arr,size);
    cout << "Majority Element : " << majority_element(arr,size);
    return 0;
}

int majority_element(int arr[], int &size){
    if (size <= 0){
        return -1;
    }else{
        int element = arr[0], count = 1;
        for (int i = 1; i < size; i++){
            if (arr[i] == element){
                count++;
            }else{
                count--;
            }
            if (count == 0){
                element = arr[i];
                count++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < size; i++){
            if (arr[i] == element){
                cnt++;
            }
        }
        if (cnt > (size/2)){
            return element;
        }
        return -1;
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