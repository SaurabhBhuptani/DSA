// Count the number of subarrays with given xor K
// Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

#include <iostream>
#include <map>
using namespace std;
int subarrays_with_xor(int arr[], int &size, int reqxor);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5, reqxor = 6;
    int arr[capacity] = {3,1,2,4,2};
    cout << "Array : ";
    display(arr,size);
    cout << "Subarrays with required xor : " << subarrays_with_xor(arr,size,reqxor) << endl;
    return 0;
}

int subarrays_with_xor(int arr[], int &size, int reqxor){
    if (size <= 0){
        return 0;
    }else{
        map<int, int> mp;
        int count = 0, xr = 0, temp = 0;
        mp[xr]++;
        for (int i = 0; i < size; i++){
            xr ^= arr[i];
            temp = xr ^ reqxor;
            count += mp[temp];
            mp[xr]++;;
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