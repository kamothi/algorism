#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int dp[500][500];
    int arr[500][500];
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    for(int i = n - 1;i >= 0;i--){
        for(int j = i;j >= 0;j--){
            if(i == n - 1)
                dp[i][j] = arr[i][j];
            else{
                dp[i][j] = max(dp[i + 1][j],dp[i + 1][j + 1]) + arr[i][j];
            }
        }
    }
    cout << dp[0][0];
}
