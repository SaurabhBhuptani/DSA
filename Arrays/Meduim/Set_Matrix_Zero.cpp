// Set matrix zero
// Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

#include <iostream>
#include <vector>
using namespace std;
void set_zero(vector<vector<int>> &arr, int &row, int &col);
void display(vector<vector<int>> &arr, int row, int col);

int main(){
    int capacity = 10, row = 3, col = 3;
    vector<vector<int>> arr = {{2,0,4},{1,3,9},{0,6,7}};
    cout << "Original Matrix :" << endl;
    display(arr,row,col);
    set_zero(arr,row,col);
    cout << "New Matrix :" << endl;
    display(arr,row,col);
    return 0;
}

void set_zero(vector<vector<int>> &arr, int &row, int &col){
    if (row <= 0 || col <= 0){
        return;
    }else{
        int col0 = arr[0][0];
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (arr[i][j] == 0){
                    if (j == 0){
                        col0 = 0;
                    }else{
                        arr[i][0] = 0;
                    }
                    arr[0][j] = 0;
                }
            }
        }
        for (int i = row-1; i > 0; i--){
            for (int j = col-1; j > 0; j--){
                if (arr[i][0] == 0 || arr[0][j] == 0){
                    arr[i][j] = 0;
                }
            }
        }
        for (int i = col-1; i > 0; i--){
            if (arr[0][0] == 0){
                arr[0][i] = 0;
            }
        }
        for (int i = row-1; i >= 0; i--){
            if (col0 == 0){
                arr[i][0] = 0;
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