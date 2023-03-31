#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[1001];
    int dp[1001] = {0,};
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n;i++){
        int tmp = arr[i];
        if(i != 1 && dp[i] == 0) continue;
        for(int j=tmp;j>0;j--){
            if(i+j > n) continue;
            if(dp[i+j] != 0) continue;
            else dp[i+j] = dp[i] + 1;
        }
    }
    if(n == 1) {
        cout << 0;
        return 0;
    }
    if(dp[n] == 0) cout << -1;
    else cout << dp[n];
}
