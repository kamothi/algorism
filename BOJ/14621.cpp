#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char school[1001];
int node[1001];
pair<pair<int,int>,int> v[10000];
int Size[1001];

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second < b.second;
}

void make_set(int n){
    for(int i=1;i<=n;i++) node[i] = i;
}

int Find(int x){
    if(node[x] == x) return x;
    return Find(node[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    //if(a == b) return;
    if(Size[a] < Size[b]) swap(a,b);
    node[b] = a;
    Size[a] += Size[b];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; // 학교, 도로
    cin >> n >> m;
    int result = 0;
    for(int i=1;i<=n;i++) cin >> school[i];
    for(int i=0;i<m;i++){
        int tmp1,tmp2,tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        v[i] = {{tmp1,tmp2},tmp3};
    }
    sort(v,v+m,cmp);

    make_set(n);
    for(int i=1;i<=n;i++) Size[i] = 1;

    for(int i=0;i<m;i++){
        int f = v[i].first.first;
        int s = v[i].first.second;
        if(school[f] == school[s]) continue;
        if(Find(f) != Find(s)){
            Union(f,s);
            result += v[i].second;
        }
    }
    for(int i=1;i<=n;i++){
        if(Size[i] == n){
            cout << result;
            return 0;
        }
    }
    cout << -1;



}
