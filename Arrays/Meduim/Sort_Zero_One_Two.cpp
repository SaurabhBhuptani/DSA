// Sort an array of 0s, 1s and 2s
// Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. (Expected: single pass-O(N) and constant space)

#include <iostream>
using namespace std;
void sort_zero_one_two(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10;
    int arr[capacity] = {1,0,0,2,1,0,2,1,0,2};
    cout << "Original Array : ";
    display(arr,size);
    sort_zero_one_two(arr,size);
    cout << "Sorted Array : ";
    display(arr,size);
    return 0;
}

void sort_zero_one_two(int arr[], int &size){
    if (size <= 1){
        return;
    }else{
        int i = size-1, k = 0, count = size-1;
        while (i > 0 && count != 0){
            if (arr[i] == 0){
                for (int j = i; j > 0; j--){
                    arr[j] = arr[j-1];
                }
                arr[0] = 0;
                k++;
            }else{
                i--;
            }
            count--;
        }
        k++;
        while (k < size && count != size-1){
            if (arr[k] == 2){
                for (int j = k; j < size; j++){
                    arr[j] = arr[j+1];
                }
                arr[size-1] = 2;
            }else{
                k++;
            }
            count++;
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