#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[301];
    int dp[301];

    for(int i=1;i<=n;i++) cin>>arr[i];

    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i=3;i<=n;i++){
        dp[i] = arr[i] + max((dp[i-3] + arr[i-1]),dp[i-2]);
    }
    cout << dp[n];


}
