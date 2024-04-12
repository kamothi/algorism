#include<iostream>
#include<vector>

using namespace std;

vector<int> v[200001];
vector<int> v2[200001];
bool check[200001];
bool visited[200001];

void dfs(int n){
    visited[n] = 1;
    check[n] = 1;

    for(int i=0;i<v[n].size();i++){
        if(!visited[v[n][i]]) dfs(v[n][i]);
    }
}

void dfsv2(int n){
    visited[n] = 1;
    check[n] = 1;

    for(int i=0;i<v2[n].size();i++){
        if(!visited[v2[n][i]]) dfsv2(v2[n][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v2[b].push_back(a);
    }

    bool success = true;
    dfs(1);
    for(int i=1;i<=n;i++) {
        if(!check[i]) success = 0;
        visited[i] = 0;
        check[i] = 0;
    }

    dfsv2(1);
    for(int i=1;i<=n;i++) {
        if(!check[i]) success = 0;
    }

    if(success) cout << "YES";
    else cout << "NO";
}
