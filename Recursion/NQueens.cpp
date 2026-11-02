#include<iostream>
#include<string>
using namespace std;

const int n = 4;

void print(char m[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------" << endl;
}

bool isSafe(char m[n][n], int row, int col){
    for(int i = 0; i < row; i++){
        if(m[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col ; i >= 0 && j >= 0; i--, j--){
        if(m[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col ; i >= 0 && j < n; i--, j++){
        if(m[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void nQueens(char m[n][n], int row){
    if(row == n){
        print(m);
        return;
    }
    for(int col = 0; col < n; col++){
        if(isSafe(m, row, col)){
            m[row][col] = 'Q';
            nQueens(m, row + 1);
            m[row][col] = '.';
        }
    }
}

int main() {
    char board[n][n];

    // Initialize the board with empty cells ('.')
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    cout << "All possible solutions for " << n << "-Queens:" << endl;
    nQueens(board, 0);

    return 0;
}
