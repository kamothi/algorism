#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int arr[100000];
    int dp[100000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    dp[0] = arr[0];
    int result=dp[0];
    for(int i=1;i<n;i++){
        dp[i] = max(arr[i]+dp[i-1],arr[i]);
        result = max(result,dp[i]);
    }
    cout << result;
}
