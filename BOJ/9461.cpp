#include<iostream>
#include<algorithm>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    int t,n;

    cin >> t;
    while(t--){
        cin >>n;
        long long dp[101];
        dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] =2, dp[5] = 2;

        for(int i=6;i<=n;i++) dp[i] = dp[i-1] + dp[i-5];

         cout << dp[n] << "\n";
    }
}

