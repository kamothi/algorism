#include<iostream>
#include<algorithm>

using namespace std;

pair<int,int> p[1500000];
int dp[1500000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        p[i] = {a,b};
    }
    int result = 0;
    int tmp = 0;

    for(int i=0;i<=n;i++){
        tmp = max(tmp,dp[i]);
        if(i+p[i].first > n) continue;
        dp[i+p[i].first] = max(tmp + p[i].second, dp[i+p[i].first]);
    }

    cout << tmp;

}
