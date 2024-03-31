#include<iostream>

using namespace std;

const int MAX = 3074;
char board[MAX][MAX*2 -1];

void func(int n, int x, int y){
    if(n==3){
        board[x][y] = board[x+1][y-1] = board[x+1][y+1] = '*';
        for(int i=y-2; i<=y+2; i++)
            board[x+2][i] = '*';
        return;
    }
    int half = n/2;
    func(half, x, y);
    func(half, x+half, y-half);
    func(half, x+half, y+half);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        fill(board[i], board[i]+n*2-1, ' ');
    func(n,0,n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n*2-1; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
