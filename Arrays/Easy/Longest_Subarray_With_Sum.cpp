// Longest subarray with given sum K(positives)
// Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

#include <iostream>
using namespace std;
int longest_subarray_with_sum(int arr[], int &size, int reqsum);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5, reqsum = 10;
    int arr[capacity] = {10,6,2,2,7};
    cout << "Array : ";
    display(arr,size);
    cout << "Length of Largest Subarray with Required Sum : " << longest_subarray_with_sum(arr,size,reqsum) << endl;
    return 0;
}

int longest_subarray_with_sum(int arr[], int &size, int reqsum){
    if (size <= 0){
        return -1;
    }else{
        int sum = 0, maxlen = 0, i = 0;
        for (int j = 0; j < size; j++){
            if (j < size){
                sum += arr[j];
            }
            while (i <= j && sum > reqsum){
                sum -= arr[i];
                i++;
            }
            if (sum == reqsum){
                if (maxlen < (j-i+1)){
                    maxlen = (j-i+1);
                }
            }
        }
        return maxlen;
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