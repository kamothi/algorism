#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n,m; // 세로 가로
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
char board[10][10];
pair<int,int> red;
pair<int,int> blue;
pair<int,int> hole;
bool visited[10][10][10][10];

struct nowValue{
    pair<int,int> redPos;
    pair<int,int> bluePos;
    int cnt;
};


int checkFinish(){
    queue<nowValue> q;
    q.push({red,blue,0});
    visited[red.first][red.second][blue.first][blue.second] = true;
    while(!q.empty()){
        nowValue now = q.front();
        q.pop();
        if(now.cnt > 10) continue;
        if(board[now.redPos.first][now.redPos.second] == 'O') return now.cnt;
        for(int i=0;i<4;i++){
            int nxr = now.redPos.first;
            int nyr = now.redPos.second;
            int nxb = now.bluePos.first;
            int nyb = now.bluePos.second;
            int cntR = 0; int cntB =0;
            while((board[nxr + dx[i]][nyr + dy[i]] != '#' && board[nxr][nyr] != 'O')){
                nxr += dx[i];
                nyr += dy[i];
                cntR++;
            }
            while((board[nxb + dx[i]][nyb + dy[i]] != '#' && board[nxb][nyb] != 'O')){
                nxb += dx[i];
                nyb += dy[i];
                cntB++;
            }
            if(board[nxb][nyb] == 'O') continue;
            if(visited[nxr][nyr][nxb][nyb]) continue;
            if(nxr == nxb && nyr == nyb){
                cntR > cntB ? (nxr -= dx[i],nyr -= dy[i]) : (nxb -= dx[i],nyb -= dy[i]);
            }
            if(now.cnt < 10){
                q.push({make_pair(nxr,nyr),make_pair(nxb,nyb),now.cnt + 1});
                visited[nxr][nyr][nxb][nyb] = true;
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
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 'R') red = make_pair(i,j);
            if(board[i][j] == 'B') blue = make_pair(i,j);
            if(board[i][j] == 'O') hole = make_pair(i,j);
        }
    }
    cout << checkFinish();

}
