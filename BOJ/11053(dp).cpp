#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,Max=1;
    int arr[1000],dp[1000];

    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    dp[0] = 1;
    for(int i=1;i<n;i++){
        Max = 1;
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]) Max = max(dp[j] + 1,Max);
        }
        dp[i] = Max;
    }
    Max = -1;
    for(int i=0;i<n;i++){
        Max = max(dp[i],Max);
    }
    cout << Max;
}
