// Count subarray sum equals K
// Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

#include <iostream>
#include <map>
using namespace std;
int subarrays_with_sum(int arr[], int &size, int reqsum);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5, reqsum = 6;
    int arr[capacity] = {3,1,2,4,2};
    cout << "Array : ";
    display(arr,size);
    cout << "Subarrays with Required Sum : " << subarrays_with_sum(arr,size,reqsum) << endl;
    return 0;
}

int subarrays_with_sum(int arr[], int &size, int reqsum){
    if (size <= 0){
        return -1;
    }else{
        map<int, int> mp;
        int count = 0, sum = 0, temp = 0;
        mp[sum]++;
        for (int i = 0; i < size; i++){
            sum += arr[i];
            temp = sum - reqsum;
            count += mp[temp];
            mp[sum]++;
        }
        return count;
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