// Stock buy and sell
// You are given an array of prices where prices[i] is the price of a given stock on an ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <iostream>
using namespace std;
int buy_and_sell(int arr[], int &size);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {7,3,5,4,1};
    cout << "Array : ";
    display(arr,size);
    cout << "Max Profit Possible : " << buy_and_sell(arr,size);
    return 0;
}

int buy_and_sell(int arr[], int &size){
    if (size <= 1){
        return 0;
    }else{
        int min = INT16_MAX, diff = 0;
        for (int i = 0; i < size; i++){
            if (min > arr[i]){
                min = arr[i];
            }
            if (diff < arr[i] - min){
                diff = arr[i] - min;
            }
        }
        return diff;
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