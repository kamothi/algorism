#include<iostream>
#include<queue>

using namespace std;

int n,m;
int h,w,sr,sc,fr,fc;
int map[1001][1001];
bool visited[1001][1001];
int result = 1e9;
int sum[1001][1001];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


bool check(int r, int c){
    return ((1 <= r) && (r <= n) && (1 <= c) && (c <= m));
}

void bfs(){
    queue<pair<pair<int,int>,int>> q;
    visited[sr][sc] = true;
    q.push({{sr,sc},0});

    while(!q.empty()){
        int nowR = q.front().first.first;
        int nowC = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(nowR == fr && nowC == fc){
            result = cnt;
            return;
        }

        for(int i=0;i<4;i++){
            int nextR = nowR + dx[i];
            int nextC = nowC + dy[i];
            if(!visited[nextR][nextC] && check(nextR+h-1,nextC) && check(nextR,nextC+w-1)
            && check(nextR+h-1,nextC+w-1) && check(nextR,nextC)
               && sum[nextR+h-1][nextC+w-1]-sum[nextR-1][nextC+w-1]-sum[nextR+h-1][nextC-1]+sum[nextR-1][nextC-1] <= 0){
                visited[nextR][nextC] = true;
                q.push({{nextR,nextC},cnt+1});
            }

        }
    }
}


// 최소 횟수로 이동, 만약 못가면 -1
// 아마 직사각하여 크기로 결정해야할듯 함
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> map[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + map[i][j];
        }
    }

    cin >> h >> w >> sr >> sc >> fr >> fc;


    bfs();
    if(result != 1e9) cout << result;
    else cout << -1;



}
