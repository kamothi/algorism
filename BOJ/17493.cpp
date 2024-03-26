#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// tree 정점 개수
int n, m;
vector<int> tree[200001];
bool visited[200001];
int result;


int dfs(int now){
    visited[now] = 1;


    int check[3] = {0,};
    for(int i=0;i<tree[now].size();i++){
        if(!visited[tree[now][i]]){
            check[dfs(tree[now][i])]++;
        }
    }
    if(check[0] != 0){
        result++;
        return 1;
    }
    if(check[1] != 0){
        return 2;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && !dfs(i)) result++;
    }

    cout << result;
}
