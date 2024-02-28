#include<iostream>
#include<memory.h>
using namespace std;

long long dp[5001];
int t,l;

long long solve(int n){
    if(n%2 ==1) return 0;
    if(n==0||n==2) return 1;

    long long& tmp = dp[n];
    if(tmp != -1) return tmp;

    tmp = 0;
    for(int i=2;i<=n;i++){
        tmp += solve(i-2)*solve(n-i);
        tmp %= 1000000007;
    }

    return tmp;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    memset(dp,-1,sizeof(dp));

    while(t--){
        cin >> l;
        cout << solve(l) << "\n";
    }
    
}

