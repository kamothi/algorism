#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int temp1,temp2;
    int dp[5001];
    dp[1] = -1;
    dp[2] = -1;
    dp[3] = 1;
    dp[4] = -1;
    dp[5] = 1;
    cin >> n;
    for(int i=6;i<=n;i++){
        if(dp[i-3] == -1 && dp[i-5] == -1){
            dp[i] = -1;
            continue;
        }
        temp1 = dp[i-3] + 1;
        temp2 = dp[i-5] + 1;
        if(temp1 == 0) dp[i] = dp[i-5] + 1;
        else if(temp2 == 0) dp[i] = dp[i-3] + 1;
        else dp[i] = min(temp1,temp2);
    }
    cout << dp[n];
}
