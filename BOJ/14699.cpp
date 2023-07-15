#include<iostream>
#include<vector>

using namespace std;

int n, m; //쉼터의 수, 등산로의 수
vector<int> graph[5001];
vector<int> v(5001); // 쉼터의 높이
vector<int> dp(5001);

int find_rest(int k){
    if(dp[k] != -1) return dp[k];
    dp[k] = 1;
    for(int i=0;i<graph[k].size();i++){
        dp[k] = max(dp[k],find_rest(graph[k][i])+1);
    }
    return dp[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        cin >> v[i];
        dp[i] = -1;
    }
    for(int i=0;i<m;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        if(v[tmp1] < v[tmp2]) graph[tmp1].push_back(tmp2);
        else graph[tmp2].push_back(tmp1);
    }

    for(int i=1;i<=n;i++) cout << find_rest(i) << "\n";

}
