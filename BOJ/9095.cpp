#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long long dp[11];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int temp;
    cin >> n;
    for(int i=4;i<=11;i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    while(n--){
        cin >> temp;
        cout << dp[temp] << '\n';
    }
}
