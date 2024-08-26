// Two Sum : check if a pair with given sum exists in array
// Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
// Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

#include <iostream>
using namespace std;
string target(int arr[], int &size, int target_sum, int arr2[]);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5, target_sum = 10;
    int arr[capacity] = {2,5,4,5,3};
    int arr2[2];
    cout << "Array : ";
    display(arr,size);
    cout << "Target Sum Possible : " << target(arr,size,target_sum,arr2) << endl;
    cout << "Index -> " << arr2[0] << ":" << arr2[1] << endl;
    return 0;
}

string target(int arr[], int &size, int target_sum, int arr2[]){
    if (size <= 1){
        arr2[0] = -1;
        arr2[1] = -1;
        return "NO";
    }else{
        for (int i = 0; i < size; i++){
            for (int j = i+1; j < size; j++){
                if (arr[i] + arr[j] == target_sum){
                    arr2[0] = i;
                    arr2[1] = j;
                    return "YES";
                }
            }
        }
        arr2[0] = -1;
        arr2[1] = -1;
        return "NO";
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