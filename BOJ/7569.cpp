#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

// 1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토가 없는 곳

struct pos{
    int x;
    int y;
    int z;
    int value = 0;
};

int m,n,h;
bool visited[100][100][100];
int dx[6]={1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int arr[100][100][100];
queue<pos> q;
int cnt = 0;
int result = 0;


bool valid(int x, int y, int z){
    if(x>n-1 || x < 0 || y > m-1 || y < 0 || z > h-1 || z < 0) return false;
    return true;
}

void checkTomato(){
    while(!q.empty()){
        pos now = q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int nz = now.z + dz[i];
            if(valid(nx,ny,nz) && !visited[nx][ny][nz] && arr[nx][ny][nz] == 0){
                arr[nx][ny][nz] = 1;
                q.push({nx,ny,nz,now.value+1});
                visited[nx][ny][nz] = true;
                cnt--;
                result = max(result,now.value+1);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> arr[j][k][i];
                if(arr[j][k][i] == 0){
                    cnt++;
                }
                if(arr[j][k][i] == 1) q.push({j,k,i,0});
            }
        }
    }
    checkTomato();
    if(cnt > 0) cout << -1;
    else cout << result;

}
