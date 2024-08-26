// Rearrange array elements by sign
// There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.
// Note: Start the array with positive elements.

#include <iostream>
using namespace std;
void rearrange_by_sign(int arr2[], int &size, int arr[]);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10;
    int arr2[capacity] = {1,0,-4,3,6,4,-3,-7,8,-9};
    int arr[size];
    cout << "Original Array : ";
    display(arr2,size);
    rearrange_by_sign(arr2,size,arr);
    cout << "Rearranged Array : ";
    display(arr,size);
    return 0;
}

void rearrange_by_sign(int arr2[], int &size, int arr[]){
    if (size <= 1){
        return;
    }else{
        int pos[size], neg[size], sizepos = 0, sizeneg = 0;
        for (int i = 0; i < size; i++){
            if (arr2[i] >= 0){
                pos[sizepos] = arr2[i];
                sizepos++;
            }else{
                neg[sizeneg] = arr2[i];
                sizeneg++;
            }
        }
        if (sizepos>sizeneg){
            for (int i = 0; i < sizeneg; i++){
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
            int index = sizeneg*2;
            for (int i = sizeneg;i < sizepos; i++){
                arr[index] = pos[i];
                index++;
            }
        }else{
            for (int i = 0; i < sizepos; i++){
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
            int index = sizepos*2;
            for (int i = sizepos;i < sizeneg; i++){
                arr[index] = neg[i];
                index++;
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