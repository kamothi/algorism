#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[100001];
int dp[100001];
int n,m;

void dfs(int now, int pt, int sum){
    dp[now] += sum;
    for(auto& child : tree[now]){
        if(child != pt){
            dfs(child,now,dp[now]);
        }
    }
}


// 1번이 루트
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        if(a == -1) continue;
        tree[a].push_back(i);
        tree[i].push_back(a);
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        dp[a] += b;
    }

    dfs(1,0,0);

    for(int i=1;i<=n;i++) cout << dp[i] << " ";

}
