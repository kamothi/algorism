#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n,m;
vector<int> tree[100001];
int dp[100001][17];
int depth[100001];

// 기본 세팅
void dfs(int now, int pt, int d){
    depth[now] = d;
    for(auto& child: tree[now]){
        if(child != pt){
            dp[child][0] = now;
            dfs(child,now,d+1);
        }
    }
}


void setting(){
    for(int j=1;j<17;j++)
    for(int i=1;i<=n;i++)
    dp[i][j]=dp[dp[i][j-1]][j-1];
}

int lca(int x, int y){
    if(depth[x] < depth[y]){
        swap(x,y);
    }

    int diff = depth[x] - depth[y];
    for(int i=0;diff!=0;i++){
        if(diff % 2 == 1) x = dp[x][i];
        diff/=2;
    }

    if(x==y) return x;

    for(int i=16;i>=0;i--){
        if(dp[x][i]!=dp[y][i]){
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    return dp[x][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1,0,0);
    setting();
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << "\n";
    }

}
