#include<iostream>
#include<string>
using namespace std;

const int n = 4;

void ratinAMaze(int m[n][n], int r, int c, string path, string ans[], int& ansCount){
    if(r<0 || r>=n || c<0 || c>=n || m[r][c] == 0 || m[r][c] == -1){
        return;
    }
    
    if(r == n-1 && c == n-1){
        ans[ansCount++] = path;
        return;
    }

    m[r][c] = -1;
    
    ratinAMaze(m, r + 1, c, path + "D", ans, ansCount);
    ratinAMaze(m, r - 1, c, path + "U", ans, ansCount);
    ratinAMaze(m, r, c + 1, path + "R", ans, ansCount);
    ratinAMaze(m, r, c - 1, path + "L", ans, ansCount);

    m[r][c] = 1;
}

int main() {
    int m[n][n] = {
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 },
        { 1, 1, 0, 0 },
        { 0, 1, 1, 1 }
    };

    string ans[100];
    int ansCount = 0;

    ratinAMaze(m, 0, 0, "", ans, ansCount);

    for (int i = 0; i < ansCount; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
