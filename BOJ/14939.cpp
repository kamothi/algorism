#include<iostream>
#include<algorithm>

using namespace std;


bool arr[10][10], tmp[10][10];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 1e9;

bool isCheck(int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10) return 1;
    return 0;
}


void button(int x, int y) {
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isCheck(nx, ny)) tmp[nx][ny] = !tmp[nx][ny];
    }
    tmp[x][y] = !tmp[x][y];
}


void init() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tmp[i][j] = arr[i][j];
}


bool isTrue() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (tmp[i][j]) return 1;
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            char c;
            cin >> c;
            if (c == 'O') arr[i][j] = 1;
        }
    }
    // 2^10 즉 첫번째 줄에 대한 모든 처리
    for(int s=0;s<(1<<10);s++){
        int cnt = 0;
        init();

        for (int bit = 0; bit < 10; bit++)
        {
            //첫 번째 줄의 bit 번 째 칸의 줄이 켜져있고, step을 봤을 때 이 칸을 클릭할 수 있는지 확인한다.
            if (s & (1 << bit)) {
                cnt++;
                button(0, bit);
            }
        }

        for (int x = 1; x < 10; x++){
            for (int y = 0; y < 10; y++){
                if (tmp[x-1][y]) {
                    button(x, y);
                    cnt++;
                }
            }
        }

        if (!isTrue()) {
            ans = min(cnt, ans);
        }
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;
}
