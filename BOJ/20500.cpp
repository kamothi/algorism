#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int dp[3][1516];
    dp[0][1] = 0;
    dp[0][2] = 1; dp[1][2] = 1; dp[2][2] = 0;

    for (int i = 3; i < n + 1; i++) {
        dp[0][i] = (dp[2][i - 1] + dp[1][i - 1]) % 1000000007;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % 1000000007;
        dp[2][i] = (dp[1][i - 1] + dp[0][i - 1]) % 1000000007;
    }

    cout << dp[0][n];
}
