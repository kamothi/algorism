#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int v[2][100002];
int dp[2][100002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int n;
    int sum=0;
    while(t--){
        cin >> n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n+2;j++) {
                if(j==0 || j==1) {
                    v[i][j] = 0;
                    continue;
                }
                int tmp;
                cin >> tmp;
                v[i][j] = tmp;
            }
        }
        for(int i=2;i<n+2;i++){
            dp[0][i] = max(dp[1][i-2],dp[1][i-1]) + v[1][i];
            dp[1][i] = max(dp[0][i-2],dp[0][i-1]) + v[0][i];
        }
        cout << max(dp[0][n+1],dp[1][n+1]) << "\n";
    }
}
