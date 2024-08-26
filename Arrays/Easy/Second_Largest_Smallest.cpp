// Find second smallest and second largest element in an array
// Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

#include <iostream>
using namespace std;
int* second_largest_smallest(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10;
    int arr[capacity] = {9,8,7,6,5,4,3,2,1,0};
    cout << "Array : ";
    display(arr,size);
    int* ptr = second_largest_smallest(arr,size);
    cout << "Second Largest Element : " <<  ptr[0] << endl;
    cout << "Second Smallest Element : " << ptr[1] << endl;
    delete ptr;
    return 0;
}

int* second_largest_smallest(int arr[], int &size){
    int* ans = new int[2];
    if (size <= 2){
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }else{
        int max = INT16_MIN, sec_max = INT16_MIN;
        int min = INT16_MAX, sec_min = INT16_MAX;
        for (int i = 0; i < size; i++){
            if (arr[i] > max){
                sec_max = max;
                max = arr[i];
            }
            else if (arr[i] > sec_max && arr[i] < max){
                sec_max = arr[i];
            }
            if (arr[i] < min){
                sec_min = min;
                min = arr[i];
            }
            else if (arr[i] < sec_min && arr[i] > min){
                sec_min = arr[i];
            }
        }
        ans[0] = sec_max;
        ans[1] = sec_min;
        return ans;
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