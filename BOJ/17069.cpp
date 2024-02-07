#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[32][32];
long long dp[32][32][3];

bool check(int x,int y){
    return (x>=0 && y>=0 && x<n && y < n && map[x][y] != 1);
}

// pos 0,1,2 가로, 대각선 세로

long long solve(int x, int y,int pos){
    if(x == n-1 && y == n-1) return 1;
    if(dp[x][y][pos]) return dp[x][y][pos];

    dp[x][y][pos] = 0;

    if(pos == 0){
        if(check(x+1,y+1) && map[x][y+1] == 0 && map[x+1][y] == 0) dp[x][y][pos] += solve(x+1,y+1,1);
        if(check(x,y+1)) dp[x][y][pos] += solve(x,y+1,0); 
    }
    if(pos == 1){
        if(check(x,y+1)) dp[x][y][pos] += solve(x,y+1,0);
        if(check(x+1,y+1) && map[x][y+1] == 0 && map[x+1][y] == 0) dp[x][y][pos] += solve(x+1,y+1,1);
        if(check(x+1,y)) dp[x][y][pos] += solve(x+1,y,2);
    }
    if(pos == 2){
        if(check(x+1,y+1) && map[x][y+1] == 0 && map[x+1][y] == 0) dp[x][y][pos] += solve(x+1,y+1,1);
        if(check(x+1,y)) dp[x][y][pos] += solve(x+1,y,2);
    }
    return dp[x][y][pos];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> map[i][j];
    }


    
    cout << solve(0,1,0);

}
