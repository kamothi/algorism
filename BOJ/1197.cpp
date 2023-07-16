#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int node[10000];

void make_set(int n){
    for(int i = 0; i < n; i++) node[i] = i;
}

int Find(int i) {
    if(node[i] == i) return i;
    node[i] = Find(node[i]);
    return (node[i]);
}
void Union(int a, int b) {
    node[Find(a)] = Find(b);
}

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; //정점의 개수와 간선의 개수
    int result = 0;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>> edge(m);
    for(int i=0;i<m;i++){
        int tmp1,tmp2,num;
        cin >> tmp1 >> tmp2 >> num;
        edge[i] = {{tmp1,tmp2},num};
    }

    sort(edge.begin(),edge.end(),cmp);
    make_set(n);
    for(int i=0;i<m;i++){
        if(Find(edge[i].first.first) != Find(edge[i].first.second)) {
            result += edge[i].second;
            Union(edge[i].first.first,edge[i].first.second);
        }
    }
    cout << result;
}
