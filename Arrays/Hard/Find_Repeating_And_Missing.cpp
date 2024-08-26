// Find the repeating and missing numbers
// You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

#include <iostream>
#include <vector>
using namespace std;
void find_repeating_and_missing(int arr[], int &size, int ans[]);
void display(int arr[], int &size);

int main(){
    int capacity = 15, size = 10;
    int arr[capacity] = {1,2,9,6,3,4,5,3,8,10};
    int ans[2];
    find_repeating_and_missing(arr,size,ans);
    cout << "Array : ";
    display(arr,size);
    cout << "Repeating Element : ";
    cout << ans[0] << endl;
    cout << "Missing Element : ";
    cout << ans[1] << endl;
    return 0;
}

void find_repeating_and_missing(int arr[], int &size, int ans[]){
    if (size <= 1){
        return;
    }else{
        int xr = 0;
        int repeating = 0, missing = 0;
        for (int i = 0; i < size; i++){
            xr ^= arr[i];
            xr ^= (i+1);
        }
        int bitno = 0;
        while ((xr & (1<<bitno)) == 0){
            bitno++;
        }
        for (int i = 0; i < size; i++){
            if ((arr[i] & (1<<bitno)) != 0){
                repeating ^= arr[i];
            }else{
                missing ^= arr[i];
            }
            if (((i+1) & (1<<bitno)) != 0){
                repeating ^= (i+1);
            }else{
                missing ^= (i+1);
            }
        }
        int count = 0;
        for (int j = 0; j < size; j++){
            if (arr[j] == repeating){
                count++;
            }
        }
        if (count == 2){
            ans[0] = repeating;
            ans[1] = missing;
        }else{
            ans[0] = missing;
            ans[1] = repeating;
        }
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