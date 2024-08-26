// Count maximum consecutive one's in the array
// Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array

#include <iostream>
using namespace std;
int max_consecutive(int arr[], int &size, int element);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size = 5, element = 1;
    int arr[capacity] = {1,3,1,1,9};
    cout << "Array : ";
    display(arr,size);
    cout << "Max Consecutive " << element << " : " << max_consecutive(arr,size,element);
    return 0;
}

int max_consecutive(int arr[], int &size, int element){
    if (size <= 0){
        return -1;
    }else{
        int max = 0, count = 0;
        for (int i = 0; i < size; i++){
            if (arr[i] == element){
                count ++;
            }else{
                if (max < count){
                    max = count;
                }
                count = 0;
            }
        }
        return max;
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