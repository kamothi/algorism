#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
// 내리막길 1520

int n,m;
char map[50][50];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visited[50][50];
int result = 0;

bool check(int nx, int ny){
    return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

void reset(){
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            visited[i][j] = 0;
}

void bfs(int cx, int cy){
    queue<pair<pair<int,int>,int>> q;
    q.push({{cx,cy},0});
    visited[cx][cy] = 1;

    while(!q.empty()){
        pair<int,int> tmp = q.front().first;
        int cnt = q.front().second;
        q.pop();

        result = max(result,cnt);
        for(int i=0;i<4;i++){
            int nx = tmp.first + dx[i];
            int ny = tmp.second + dy[i];
            if(check(nx,ny) && !visited[nx][ny] && map[nx][ny] == 'L'){
                visited[nx][ny] = 1;
                q.push({{nx,ny},cnt+1});
            }
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> map[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 'L') {
                bfs(i,j);
                reset();
            }
        }
    }

    cout << result;

}
