// Kadane's Algorithm : maximum subarray sum in an array
// Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

#include <iostream>
using namespace std;
int largest_sum_subarray(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {-2,8,5,-1,3};
    cout << "Array : ";
    display(arr,size);
    cout << "Sum of the Largest Sum Subarray : " << largest_sum_subarray(arr,size) << endl;
    return 0;
}

int largest_sum_subarray(int arr[], int &size){
    if (size <= 0){
        return -1;
    }else{
        int max = INT16_MIN, sum = 0;
        for (int i = 0; i < size; i++){
            sum += arr[i];
            if (max < sum){
                max = sum;
            }
            if (sum < 0){
                sum = 0;
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