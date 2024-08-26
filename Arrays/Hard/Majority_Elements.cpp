// Majority Elements(N/3 times) | Find the elements that appears more than N/3 times in the array
// Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

#include <iostream>
using namespace std;
int majority_elements(int arr[], int &size, int ele[]);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10;
    int arr[capacity] = {1,3,2,2,3,1,2,3,2,3};
    int ele[2];
    int elesize = majority_elements(arr,size,ele);;
    cout << "Array : ";
    display(arr,size);
    cout << "Majority Elements : ";
    display(ele,elesize);
    return 0;
}

int majority_elements(int arr[], int &size, int ele[]){
    if (size <= 0){
        return -1;
    }else if(size == 1){
        ele[0] = arr[0];
        return 1;
    }else{
        int element1 = arr[0], count1 = 1, element2 = 0, count2 = 1;
        for (int i = 0; i < size; i++){
            if (arr[i] != element1){
                element2 = arr[i];
                break;
            }
        }
        for (int i = 1; i < size; i++){
            if (count1 == 0 && arr[i] != element2){
                element1 = arr[i];
                count1++;
            }
            else if (count2 == 0 && arr[i] != element1){
                element2 = arr[i];
                count2++;
            }
            else if (arr[i] == element1){
                count1++;
            }
            else if (arr[i] == element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < size; i++){
            if (arr[i] == element1){
                cnt1++;
            }
            else if (arr[i] == element2){
                cnt2++;
            }
        }
        if (cnt1 > (size/3)){
            ele[0] = element1;
        }
        if (cnt2 > (size/3)){
            ele[1] = element2;
        }
        return 2;
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