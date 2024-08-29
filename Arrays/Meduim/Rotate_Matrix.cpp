// Rotate image by 90 degree
// Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>> &arr, int row, int col);
void display(vector<vector<int>> &arr, int row, int col);

int main(){
    int capacity = 10, row = 3, col = 3;
    vector<vector<int>> arr = {{2,5,4},{1,3,9},{7,6,8}};
    cout << "Original Matrix :" << endl;
    display(arr,row,col);
    rotate(arr,row,col);
    cout << "90 Degree Rotated Matrix :" << endl;
    display(arr,row,col);
    return 0;
}

void rotate(vector<vector<int>> &arr, int row, int col){
    if (row <= 0 || col <= 0){
        return;
    }else{
        int temp = 0;
        for (int i = 0; i < row; i++){
            for (int j = i; j < col; j++){
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        temp = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < (col/2); j++){
                temp = arr[i][j];
                arr[i][j] = arr[i][col-j-1];
                arr[i][col-j-1] = temp;
            }
        }
    }
}

void display(vector<vector<int>> &arr, int row, int col){
    if (row <= 0 || col <= 0){
        cout << "Invalid Matrix" << endl;
    }else{
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
