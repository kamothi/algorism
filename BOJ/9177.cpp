#include<iostream>
#include <cstring>
using namespace std;

string a,b,c;
int dp[201][201];

int dfs(int x, int y){
    if(x == a.size() && y == b.size()) return 1;

    if(dp[x][y] != -1) return dp[x][y];

    if (x < a.size() && a[x] == c[x + y] && dfs(x+1,y)) return dp[x+1][y] = 1;
    if (y < b.size() && b[y] == c[x + y] && dfs(x,y+1)) return dp[x][y+1] = 1;

    return dp[x][y] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;


    int i = 1;
    while(n--){
        memset(dp,-1,sizeof(dp));
        cin >> a >> b >> c;
        dfs(0,0);
        if(dfs(0,0)) cout << "Data set " << i << ": yes\n";
        else cout << "Data set " << i << ": no\n";
        i++;
    }

}
