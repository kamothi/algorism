#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> v[40001];
int parent[40001];
int level[40001];
int cost[40001];
int visited[40001];

int find(int a, int b){
    if(level[a] < level[b]) swap(a,b);

    while(level[a] != level[b]){
        a = parent[a];
    }

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;

}

void set_tree(int node, int pnode){
    visited[node] = 1;
    parent[node] = pnode;
    level[node] = level[pnode] + 1;

    for (auto [child,c] : v[node]) {
        if(!visited[child]){
            cost[child] = cost[node] + c;
            set_tree(child, node);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n;

    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    set_tree(1,0);
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        int tmp = find(a,b);
        cout << cost[a] + cost[b] - 2*cost[tmp] << "\n";
    }



}
