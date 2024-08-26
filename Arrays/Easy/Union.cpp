// Union of two sorted arrays
// Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays. The union of two arrays can be defined as the common and distinct elements in the two arrays. NOTE: Elements in the union should be in ascending order.

#include <iostream>
using namespace std;
int sorted_union(int arr1[], int &size1, int arr2[], int &size2, int arr3[]);
void display(int arr[], int &size);

int main(){
    int capacity = 10, size1 = 7, size2 = 5;
    int arr1[capacity] = {2,3,5,7,8,9,11};
    int arr2[capacity] = {1,3,4,6,7};
    int uni[size1 + size2];
    cout << "Array 1 : ";
    display(arr1,size1);
    cout << "Array 2 : ";
    display(arr2,size2);
    int size_uni = sorted_union(arr1,size1,arr2,size2,uni);
    cout << "Union : ";
    display(uni,size_uni);
    return 0;
}

int sorted_union(int arr1[], int &size1, int arr2[], int &size2, int arr3[]){
    if (size1 <= 0 && size2 <= 0){
        cout << "Both Array Empty" << endl;
        return -1;
    }else{
        int i = 0, j = 0, k = 0, dat = INT16_MAX;
        while (i < size1 && j < size2){
            if (arr1[i] < arr2[j]){
                if (arr1[i] == dat){
                    i++;
                }else{
                    arr3[k] = arr1[i];
                    dat = arr3[k];
                    i++;
                    k++;
                }
            }else{
                if (arr2[j] == dat){
                    j++;
                }else{
                    arr3[k] = arr2[j];
                    dat = arr3[k];
                    j++;
                    k++;
                }
            }
        }
        while(i < size1){
            if (arr1[i] == dat){
                i++;
            }else{
                arr3[k] = arr1[i];
                dat = arr3[k];
                i++;
                k++;
            }
        }
        while(j < size2){
            if (arr2[j] == dat){
                j++;
            }else{
                arr3[k] = arr2[j];
                dat = arr3[k];
                j++;
                k++;
            }
        }
        return k;
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