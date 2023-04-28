#include<iostream>
#include<queue>

using namespace std;
int n,m;
struct status{
    int x;
    int y;
    int breakWall;
};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int arr[1001][1001];
int visited[1001][1001][2];
bool valid(int x, int y){
    if(x<1 || x >n || y<1 || y > m) return false;
    return true;
}

int checkMax(){
    queue<status> q;
    q.push({1,1,1});
    visited[1][1][1] = 1;

    while(!q.empty()) {
        status now = q.front();
        q.pop();
        if (now.x == n && now.y == m) {
            return visited[now.x][now.y][now.breakWall];
        }
        for (int i = 0; i < 4; i++) {
            int nextX = now.x + dx[i];
            int nextY = now.y + dy[i];
            if (valid(nextX, nextY)) {
                if (arr[nextX][nextY] == 1 && now.breakWall == 1) {
                    visited[nextX][nextY][now.breakWall - 1] = visited[now.x][now.y][now.breakWall] + 1;
                    q.push({nextX, nextY, now.breakWall - 1});
                }
                if (arr[nextX][nextY] == 0 && visited[nextX][nextY][now.breakWall] == 0) {
                    visited[nextX][nextY][now.breakWall] = visited[now.x][now.y][now.breakWall] + 1;
                    q.push({nextX, nextY, now.breakWall});
                }

            }

        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            arr[i][j+1] = s[j] - '0';
        }
    }
    cout << checkMax();

}
