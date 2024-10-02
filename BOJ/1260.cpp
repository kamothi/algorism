#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// 단순 dfs, bfs 탐색
// 작은 번호부터 방문

int n,m,s;
bool visited[1001];
vector<int> v[1001];

void dfs(int next){
    if(visited[next]) return;
    visited[next] = 1;
    cout << next << " ";

    for(int i=0;i<v[next].size();i++){
        dfs(v[next][i]);
    }
}

void bfs(int next){
    queue<int> q;
    q.push(next);
    visited[next] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int i=0;i<v[cur].size();i++){
            if(!visited[v[cur][i]]){
                q.push(v[cur][i]);
                visited[v[cur][i]] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }

    dfs(s);
    cout << "\n";
    for(int i=1;i<=n;i++){
        visited[i] = 0;
    }
    bfs(s);
}
