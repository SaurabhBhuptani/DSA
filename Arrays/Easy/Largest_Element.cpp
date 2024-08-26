// Find the largest element in an array
// Given an array, we have to find the largest element in the array.

#include <iostream>
using namespace std;
int largest_element(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10;
    int arr[capacity] = {2,5,7,9,3,6,3,8,2,3};
    cout << "Array : ";
    display(arr,size);
    cout << "Largest Element : " << largest_element(arr,size) << endl;
    return 0;
}

int largest_element(int arr[], int &size){
    if (size <= 0){
        return -1;
    }else{
        int max = INT16_MIN;
        for (int i = 0; i < size; i++){
            if (arr[i] > max){
                max = arr[i];
            }
        }
        return max;
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