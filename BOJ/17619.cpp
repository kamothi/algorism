#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int node[100001];

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

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.first.first < b.first.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>> v(n+1);
    for(int i=1;i<=n;i++){
        int x1,x2,y;
        cin >> x1 >> x2 >> y;
        v[i] = {{x1,x2},i};
    }

    make_set(n+1);
    sort(v.begin()+1,v.end(),cmp);
    int MAX = v[1].first.second;
    int idx=1;
    for (int i = 1; i < n; i++) {
        if(MAX >= v[i+1].first.first){
            Union(v[idx].second,v[i+1].second);
            MAX = max(MAX,v[i+1].first.second);
        }
        else{
            MAX = v[i+1].first.second;
            idx = i+1;
        }
    }

    while(m--){
        int node1,node2;
        cin >> node1 >> node2;
        if(Find(node1) == Find(node2)) cout << 1 <<"\n";
        else cout << 0 << "\n";
    }

}
