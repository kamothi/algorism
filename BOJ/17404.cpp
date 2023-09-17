#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int house[1000][3];
    int dp[1000][3];
    int result = 200000000;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cin >> house[i][j];
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) dp[0][j] = 5000;
        dp[0][i] = house[0][i];
        for(int j=1;j<n;j++){
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + house[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + house[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + house[j][2];
        }
        for(int j=0;j<3;j++){
            if(i == j) continue;
            result = min(result,dp[n-1][j]);
        }
    }
    cout << result;


}
