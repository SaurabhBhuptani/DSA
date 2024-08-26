// Merge two sorted arrays without extra space
// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include <iostream>
using namespace std;
void sorted_swap(int arr1[], int &size1, int arr2[], int &size2);
void swap(int arr1[], int arr2[], int index1, int index2);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size1 = 7, size2 = 4;
    int arr1[capacity] = {2,3,5,8,9,11,14};
    int arr2[capacity] = {1,4,6,7};
    cout << "Array 1 : ";
    display(arr1,size1);
    cout << "Array 2 : ";
    display(arr2,size2);
    sorted_swap(arr1,size1,arr2,size2);
    cout << "Array 1 after swap : ";
    display(arr1,size1);
    cout << "Array 2 after swap : ";
    display(arr2,size2);
    return 0;
}

void sorted_swap(int arr1[], int &size1, int arr2[], int &size2){
    if (size1 <= 0 && size2 <= 0){
        return;
    }else{
        int len = (size1 + size2);
        int gap = ((len + 1) / 2);
        int i = 0, j = 0;
        while (gap > 0){
            i = 0;
            while (i + gap < len){
                j = i + gap;
                if (i < size1 && j < size1){
                    if (arr1[i] > arr1[j]){
                        swap(arr1, arr1, i, j);
                    }
                }
                else if (i >= size1 && j >= size1){
                    if (arr2[i - size1] > arr2[j - size1]){
                        swap(arr2, arr2, i - size1, j - size1);
                    }
                }
                else{
                    if (i < size1 && j >= size1){
                        if (arr1[i] > arr2[j - size1]){
                            swap(arr1, arr2, i, j - size1);
                        }
                    }
                }
                i++;
            }
            (gap == 1)? gap = 0 : gap = (gap + 1) / 2;
        }
    }
}

void swap(int arr1[], int arr2[], int index1, int index2){
    int temp = 0;
    if (arr1[index1] > arr2[index2]){
        temp = arr1[index1];
        arr1[index1] = arr2[index2];
        arr2[index2] = temp;
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