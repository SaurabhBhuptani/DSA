// Kadane's Algorithm : print subarray with maximum subarray sum

#include <iostream>
using namespace std;
void subarray_with_largest_sum(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {-2,8,5,-1,3};
    cout << "Array : ";
    display(arr,size);
    cout << "Subarray with Largest Sum : ";
    subarray_with_largest_sum(arr,size);
    return 0;
}

void subarray_with_largest_sum(int arr[], int &size){
    if (size <= 0){
        cout << "Empty Array" << endl;
    }else{
        int max = INT16_MIN, sum = 0, start = -1, end = -1, count = 1;
        for (int i = 0; i < size; i++){
            if(sum == 0){
                start = i;
            }
            sum += arr[i];
            if (max < sum){
                max = sum;
                end = i;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        for (int i = start; i <= end; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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