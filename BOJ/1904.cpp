#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000001];

int solve(int n){
    if(dp[n]) return dp[n];
    return dp[n] = (solve(n-1) + solve(n-2))%15746;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    dp[1] = 1, dp[2] = 2;


    cout << solve(n);

}
