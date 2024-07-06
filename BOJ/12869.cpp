#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int scv[3];
int dp[61][61][61];

int solve(int a, int b, int c){
    a = max(a,0);
    b = max(b,0);
    c = max(c,0);

    if(dp[a][b][c] != -1) return dp[a][b][c];

    return dp[a][b][c] = min({
        solve(a-9,b-3,c-1)+1,
        solve(a-9,b-1,c-3)+1,
        solve(a-3,b-9,c-1)+1,
        solve(a-3,b-1,c-9)+1,
        solve(a-1,b-3,c-9)+1,
        solve(a-1,b-9,c-3)+1
    });
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0;

    for(int i=0; i<n; i++) cin >> scv[i];

    cout << solve(scv[0],scv[1],scv[2]);

}
