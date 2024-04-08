#include<iostream>

using namespace std;

int map[17][17];
int n;
int result = 0;

struct Point{
    int x;
    int y;
};

//1,1 1,2에서 시작
void dfs(Point h, Point t){
    if(h.x == n && h.y == n){
        result++;
        return;
    }
    // 가로
    if(h.x == t.x && h.y != t.y){
        // 가로
        if(h.y+1 <= n && map[h.x][h.y+1] != 1) dfs({h.x,h.y+1},h);
        // 대각선
        if(h.x+1 <= n && h.y+1 <=n && map[h.x+1][h.y+1] != 1 && map[h.x+1][h.y] != 1 && map[h.x][h.y+1] != 1) dfs({h.x+1,h.y+1},h);
    }

    // 세로
    if(h.x != t.x && h.y == t.y){
        if(h.x+1<=n && map[h.x+1][h.y] != 1) dfs({h.x+1,h.y},h);
        if(h.x+1 <= n && h.y+1 <=n && map[h.x+1][h.y+1] != 1 && map[h.x+1][h.y] != 1 && map[h.x][h.y+1] != 1) dfs({h.x+1,h.y+1},h);
    }

    // 대각선
    if(h.x != t.x && h.y != t.y){
        if(h.y+1 <= n && map[h.x][h.y+1] != 1) dfs({h.x,h.y+1},h);
        if(h.x+1 <= n && map[h.x+1][h.y] != 1) dfs({h.x+1,h.y},h);
        if(h.x+1 <= n && h.y+1 <=n && map[h.x+1][h.y+1] != 1 && map[h.x+1][h.y] != 1 && map[h.x][h.y+1] != 1) dfs({h.x+1,h.y+1},h);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }


    dfs({1,2},{1,1});

    cout << result;

}
