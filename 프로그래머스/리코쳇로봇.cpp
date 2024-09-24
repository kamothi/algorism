#include <string>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int visited[100][100];
pair<int,int> s,g;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int bfs(vector<string> board){
    queue<pair<pair<int,int>,int>> q;

    q.push({s,0});
    visited[s.first][s.second] = 1;
    
    while(!q.empty()){
        pair<int,int> cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur.first==g.first && cur.second==g.second){
            return cnt;
        }
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            while(check(nx, ny) && board[nx][ny] != 'D'){
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];
        
            if(nx==cur.first && ny==cur.second) continue;
            if(visited[nx][ny]) continue;
            else {
                q.push({{nx, ny}, cnt+1});
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
    
}

// 단순 미로 찾기
// 그래프 탐색 -> 시작 위치에서 목적지 이동 최소 거리
// 차이점은 멈출 수 있어야함.
// bfs
int solution(vector<string> board) {
    int answer = 0;
    n = board.size();
    m = board[0].size();
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++){
            if(board[i][j] == 'R') s = {i,j};
            if(board[i][j] == 'G') g = {i,j};
        }
    return bfs(board);
}
