#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    int arr[1001][1001] = {0,};
    int dp[1001][1001] = {0,};
    while(1){
        int result = 0;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> arr[i][j];
                if(arr[i][j] == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
                    result = max(dp[i][j],result);
                }
            }
        }
        cout << result << "\n";

    }
}
