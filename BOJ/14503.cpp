#include<iostream>


using namespace std;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int n,m;
int map[50][50];
int result = 0;
int nowr, nowc, nowd;

bool check(int r, int c){
    return (r >= 0 && c >= 0 && r < n && c < m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> nowr >> nowc >> nowd;

    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++) cin >> map[i][j];

    while(1){
        int flag = false;
        if(map[nowr][nowc] == 0) {
            result++;
            map[nowr][nowc] = 2;
        }

        int nextD = nowd;
        int nextR, nextC;

        for (int i=0; i<4; i++) {
        nextD = (nextD + 3) % 4;
        nextR = nowr + dr[nextD];
        nextC = nowc + dc[nextD];

        if (map[nextR][nextC] == 0) {
            nowr = nextR;
            nowc = nextC;
            nowd = nextD;
                
            flag = true;
            break;
        }
    }
        if(flag) continue;

        int backDirection = nowd-2;
        // 3-> 1, 2 -> 0, 1 -> -1,3  , 0 -> -2,2
        if(backDirection < 0) backDirection += 4;

        if(check(nowr + dr[backDirection],nowc + dc[backDirection]) && map[nowr + dr[backDirection]][nowc + dc[backDirection]] != 1){
            nowr = nowr + dr[backDirection];
            nowc = nowc + dc[backDirection];
        }
        else{
            break;
        }
    }
 
    cout << result;

}
