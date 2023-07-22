#include<iostream>
#include<queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;
char map[101][101];
bool visited[101][101];
bool check(int x, int y){
    if(x >= 0 && x <n && y >= 0 && y<m) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }

    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    while(1){
        int nex = q.front().first.first;
        int ney = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(nex == n-1 && ney == m-1){
            cout << cnt;
            return 0;
        }
        for(int i=0;i<4;i++){
            if(check(dx[i] + nex, dy[i] + ney) && !visited[dx[i] + nex][dy[i] + ney] && map[dx[i] + nex][dy[i] + ney] == '1'){
                visited[dx[i] + nex][dy[i] + ney] = true;
                q.push({{dx[i] + nex,dy[i] + ney},cnt+1});
            }
        }
    }
}
