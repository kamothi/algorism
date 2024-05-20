#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int result;
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c;
            arr[i][j] = c-'0';
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == 1){
                dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                result = max(dp[i][j],result);
            }
        }
    }

    cout << result*result;
}
