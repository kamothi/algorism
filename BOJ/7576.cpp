#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<pair<int,int>,int> pp;
int n,m;
int cnt = 0;
int result = 0;
int arr[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[1000][1000];
queue<pp> q;

bool valid(int x, int y){
    if(x>m-1 || x<0 || y<0 || y>n-1) return false;
    return true;
}

void findMinDay(){
    while(!q.empty()){
        pp next = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = next.first.first + dx[i],ny = next.first.second + dy[i];
            if(valid(nx,ny) && !visited[nx][ny] && arr[nx][ny] == 0){
                arr[nx][ny] = 1;
                q.push(make_pair(make_pair(nx,ny),next.second+1));
                visited[nx][ny] = true;
                result = max(next.second + 1,result);
                cnt--;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push(make_pair(make_pair(i,j),0));
            }
            if(arr[i][j] == 0) cnt++;
        }
    }
    findMinDay();
    if(cnt > 0) cout << -1;
    else cout << result;
}
