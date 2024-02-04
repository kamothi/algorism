#include<iostream>

using namespace std;
// 내리막길 1520

int map[500][500];
int dp[500][500];
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool check(int nx, int ny){
    return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

int dfs(int cx, int cy){
    if(cx == n-1 && cy == m-1){
        return 1;
    }
    int tmp = dp[cx][cy];
    if(dp[cx][cy] != -1){
        return tmp;
    }
    dp[cx][cy] = 0;
    for(int i=0;i<4;i++){
        int nx = dx[i] + cx;
        int ny = dy[i] + cy;

        if(check(nx,ny) && map[cx][cy] > map[nx][ny]){
            dp[cx][cy] += dfs(nx, ny);
        }
    }
    return dp[cx][cy];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 가로 세로(<=500)
    cin >> n >> m;

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j] = -1;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> map[i][j];

    cout << dfs(0,0);

}
