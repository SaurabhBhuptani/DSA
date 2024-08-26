// Next Permutation : find next lexicographically greater permutation
// Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers. If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

#include <iostream>
using namespace std;
void next_permutation(int arr[], int &size);
void display(int arr[], int &size);
void reverse(int arr[], int &size, int index);
void exchange(int arr[], int a, int b);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {3,2,4,5,6};
    cout << "Array : ";
    display(arr,size);
    cout << "Next Permutation : ";
    next_permutation(arr,size);
    display(arr,size);
    return 0;
}

void next_permutation(int arr[], int &size){
    if (size <= 1){
        return;
    }else{
        int index = -1;
        for (int i = size-2; i >= 0; i--){
            if (arr[i] < arr[i+1]){
                index = i;
                break;
            }
        }
        if (index == -1){
            reverse(arr,size,0);
            return;
        }
        for (int i = size-1; i >= 0; i--){
            if (arr[i] > arr[index]){
                exchange(arr,i,index);
                break;
            }
        }
        reverse(arr,size,index+1);
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

void reverse(int arr[], int &size, int index){
    int temp = 0;
    for (int i = index; i < size; i++){
        temp = arr[size-1];
        for (int j = size-1; j >= i; j--){
            arr[j] = arr[j-1];
        }
        arr[i] = temp;
    }
}

void exchange(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}