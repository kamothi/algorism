#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

bool visited[101][101];
int map[101][101];
int out[101][101];
int n,m,result;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isTrue(int x,int y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void check(){
    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();

        if(visited[now.first][now.second]) continue;

        visited[now.first][now.second] = true;

        for(int i=0;i<4;i++){
            int nx = dx[i] + now.first;
            int ny = dy[i] + now.second;
            if(!isTrue(nx, ny)) continue;
            if(map[nx][ny] == 1){
                out[nx][ny]++;
            }else if(!visited[nx][ny]){
                q.push({nx,ny});
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
        }
    }

    while(1){
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        memset(out, 0, sizeof(out));

        check();

        for (int i = 1; i < n - 1; i++){
            for (int j = 1; j < m - 1; j++){
                if (out[i][j] >= 2){
                    map[i][j] = 0;
                    flag = true;
                }
            }
        }

        if (flag) result++;
        else break;
    }

    cout << result;


}
