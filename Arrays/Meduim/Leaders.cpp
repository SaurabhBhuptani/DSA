// Leaders in an array
// Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

#include <iostream>
using namespace std;
int find_leaders(int arr[], int &size, int lead[]);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5;
    int arr[capacity] = {3,7,5,6,4};
    int lead[size];
    cout << "Array : ";
    display(arr,size);
    int leadsize = find_leaders(arr,size,lead);
    cout << "Leaders : ";
    display(lead,leadsize);
    return 0;
}

int find_leaders(int arr[], int &size, int lead[]){
    if (size <= 0){
        lead[0] = -1;
        return 1;
    }else{
        int max = 0, j = 0;
        for (int i = size-1; i >= 0; i--){
            if (arr[i] > max){
                max = arr[i];
                lead[j] = max;
                j++;
            }
        }
        return j;
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