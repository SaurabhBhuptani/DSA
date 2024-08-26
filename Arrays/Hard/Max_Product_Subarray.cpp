// Maximum product subarray in an array
// Given an array that contains both negative and positive integers, find the maximum product subarray.

#include <iostream>
using namespace std;
int max_product_subarray(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {1,2,-4,-3,0};
    cout << "Array : ";
    display(arr,size);
    cout << "Product of Max Product Subarray : " << max_product_subarray(arr,size);
    return 0;
}

int max_product_subarray(int arr[], int &size){
    if (size <= 0){
        return -1;
    }else{
        int start = 1, end = 1, ans = INT16_MIN;
        for(int i = 0; i < size; i++){
            if (start == 0){
                start = 1;
            }
            if (end == 0){
                end = 1;
            }
            start *= arr[i];
            end *= arr[(size-1)-i];
            ans = ans < (((start > end)? start : end))? ((start > end)? start : end) : ans;
        }
        return ans;
    }
}

void display(int arr[], int &size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}