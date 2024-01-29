#include<iostream>
#include<algorithm>

using namespace std;

bool t(pair<int,int> a, pair<int, int> b){
    return a.first < b.first;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    int dp[100];
    int result = 0;
    cin >> n;

    pair<int,int> tmp[100];

    for(int i=0;i<n;i++){
        dp[i] = 1;
        cin >> tmp[i].first >> tmp[i].second;
    }

    sort(tmp,tmp+n,t);

    for(int i=1;i<n;i++){
        int MAX = 0;
        for(int j=0;j<i;j++){
            if(dp[j] > MAX && tmp[j].second < tmp[i].second){
                MAX = dp[j];
            }
        }
        dp[i] = MAX + 1;
    }

    
    for(int i=0;i<n;i++) result = max(result,dp[i]);

    cout << n - result;

}
