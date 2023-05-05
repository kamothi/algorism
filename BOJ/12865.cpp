#include<iostream>
#include<algorithm>

using namespace std;

int dp[101][100001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair<int,int> product[101];
    int n,k;
    int temp=0,result = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> product[i].first >> product[i].second;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(product[i].first <= j){
                dp[i][j] = max((product[i].second + dp[i-1][j-product[i].first]),dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];

}
