#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    dp[1] = arr[1];
    dp[2] = max(arr[2],dp[1]*2);

    for(int i=3;i<=n;i++){
        dp[i] = arr[i];
        for(int j=1;j<i;j++){
            dp[i] = max(dp[i],dp[j] + dp[i-j]);
        }
    }
    cout << dp[n];
    
}
