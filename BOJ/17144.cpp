#include<iostream>
#include<vector>

using namespace std;
int r,c,t;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

bool check(int x, int y){
    if(x < 0 || y < 0 || x >= r || y >= c) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;
    int map[r][c];
    int temp[r][c];
    int sum = 0;
    int upCleaner=-1,downCleaner=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j] > 0) sum += map[i][j];
            if(map[i][j] == -1){
                if(upCleaner == -1) upCleaner = i;
                else downCleaner = i;
            }
            temp[i][j] = 0;
        }
    }
    while(t--){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int cnt = 0;
                int num = map[i][j]/5;
                if(map[i][j] == 0 || map[i][j] == -1) continue;
                for(int k=0;k<4;k++){
                    if(check(i+dx[k],j+dy[k])) continue;
                    if(map[i+dx[k]][j+dy[k]] == -1) continue;
                    cnt++;
                    temp[i+dx[k]][j+dy[k]] += num;
                }
                temp[i][j] -= (cnt*num);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                map[i][j] += temp[i][j];
                temp[i][j] = 0;
            }
        }
        sum -= map[upCleaner-1][0];
        sum -= map[downCleaner+1][0];

        for(int i = upCleaner - 1; i > 0; i--) map[i][0] = map[i-1][0];
        for(int i = 0;i<c-1;i++) map[0][i] = map[0][i+1];
        for(int i = 1;i<=upCleaner;i++) map[i-1][c-1] = map[i][c-1];
        for(int i = c-1;i>1;i--) map[upCleaner][i] = map[upCleaner][i-1];
        map[upCleaner][1] = 0;

        for (int i = downCleaner + 1; i < r - 1; i++) map[i][0] = map[i + 1][0];
        for (int i = 0; i < c - 1; i++) map[r - 1][i] = map[r - 1][i + 1];
        for (int i = r - 1; i >= downCleaner; i--) map[i][c - 1] = map[i - 1][c - 1];
        for (int i = c - 1; i > 1; i--) map[downCleaner][i] = map[downCleaner][i - 1];
        map[downCleaner][1] = 0;


    }

    cout << sum;





}
