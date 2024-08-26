// Program to generate pascal's triangle
// This problem has 3 variations. They are stated below:
// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

#include <iostream>
#include <map>
using namespace std;
int get_val(int row, int col);
void generate_row(int row);
void generate_triangle(int row);

int main(){
    int row = 5, col = 3;
    // Variation 1 :
    cout << "Value at Index : " << get_val(row-1,col-1) << endl;
    // Variation 2 :
    cout << "Generated Row : ";
    generate_row(row);
    // Variation 3 :
    cout << "Triangle :" << endl;
    generate_triangle(row);
    return 0;
}

// Variation 1 :
int get_val(int row, int col){
    if (row <= 0 || col <= 0){
        return 0;
    }else{
        int res = 1;
        for (int i = 0; i < col; i++){
            res *= row-i;
            res /= i+1;
        }
        return res;
    }
}

// Variation 2 :
void generate_row(int row){
    if (row <= 0){
        cout << "Invalid Row" << endl;
    }else{
        int res = 1;
        cout << res << " ";
        for (int i = 1; i < row; i++){
            res *= row-i;
            res /= i;
            cout << res << " ";
        }
        cout << endl;
    }
}

// Variation 3 :
void generate_triangle(int row){
    if (row <= 0){
        cout << "Invalid Row" << endl;
    }else{
        for (int i = 1; i <= row; i++){
            generate_row(i);
        }
    }
}