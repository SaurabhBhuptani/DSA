// Spiral traversal of matrix
// Given a Matrix, print the given matrix in spiral order.

#include <iostream>
#include <vector>
using namespace std;
int spiral(vector<vector<int>> &arr, int row, int col, int ans[]);
void display(vector<vector<int>> &arr, int row, int col);
void displayarr(int arr[], int &anssize);

int main(){
    int row = 3, col = 3;
    vector<vector<int>> arr = {{2,5,4},{1,3,9},{7,6,8}};
    int ans[row*col];
    int anssize = spiral(arr,row,col,ans);;
    cout << "Original Matrix :" << endl;
    display(arr,row,col);
    cout << "Spiral :" << endl;
    displayarr(ans,anssize);
    return 0;
}

int spiral(vector<vector<int>> &arr, int row, int col, int ans[]){
    if (row <= 0 || col <= 0){
        ans[0] = -1;
        return 1;
    }else{
        int top = 0, bottom = row-1, right = col-1, left = 0, count = 0;
        while (top <= bottom && left <= right){
            count = count;
            for (int i = left; i <= right; i++){
                ans[count] = arr[top][i];
                count++;
            }
            top++;
            count = count;
            for (int i = top; i <= bottom; i++){
                ans[count] = arr[i][right];
                count++;
            }
            right--;
            count = count;
            if (top <= bottom){
                for (int i = right; i >= left; i--){
                    ans[count] = arr[bottom][i];
                    count++;
                }
                bottom--;
            }
            count = count;
            if (left <= right){
                for (int i = bottom; i >= top; i--){
                    ans[count] = arr[i][left];
                    count++;
                }
                left++;
            }
        }
        return row*col;
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

void displayarr(int arr[], int &size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}