#include<iostream>
#include<queue>
using namespace std;

// 각 지점에서 목표지점까지의 거리 출력
// 목표지점은 한 개 이기에 목표지점에서 다른 지점으로 bfs
int n, m;
pair<int,int> s;
int result[1000][1000];
int map[1000][1000];
bool visited[1000][1000];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(int x, int y){
    return (x >= 0 && x < n && y >=0 && y < m);
}

void bfs(pair<int,int> now){
    queue<pair<pair<int,int>,int>> q;
    q.push({{now},0});
    visited[now.first][now.second] = 1;

    while(!q.empty()){
        pair<int,int> cur = q.front().first;
        int cnt = q.front().second;
        result[cur.first][cur.second] = cnt;
        q.pop();
        for(int i=0;i<4;i++){
            if(check(dx[i]+cur.first, dy[i]+cur.second) && !visited[dx[i]+cur.first][dy[i]+cur.second] && map[dx[i]+cur.first][dy[i]+cur.second] != 0){
                q.push({{dx[i]+cur.first,dy[i]+cur.second},cnt+1});
                visited[dx[i]+cur.first][dy[i]+cur.second] = 1;
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 2) s = {i,j};
            if(map[i][j] == 1) result[i][j] = -1;
        }
    }

    bfs(s);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}
