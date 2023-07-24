#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int node[1001];
void make_set(int n){
    for(int i = 0; i <= n; i++) node[i] = i;
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
bool cmp2(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return a.second > b.second;
}
pair<pair<int,int>,int> v[500000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int cnt = 0,cnt2=0;
    cin >> n >> m;
    make_set(n);
    int t = 0;
    for(int i=0;i<m+1;i++){
        int tmp1,tmp2,tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        if(tmp1 == 0 || tmp2 == 0) {
            if(tmp3 == 0) {
                cnt++;
                cnt2++;
            }
            Union(tmp1,tmp2);
            continue;
        }
        v[t] = {{tmp1,tmp2},tmp3};
        t++;
    }
    sort(v,v + m,cmp);
    for(int i=0;i<m;i++){
        int f = v[i].first.first,s = v[i].first.second;
        if(Find(f) != Find(s)){
            Union(f,s);
            if(v[i].second == 0) cnt++;
        }
    }
    make_set(n);
    sort(v,v + m,cmp2);
    for(int i=0;i<m;i++){
        int f = v[i].first.first,s = v[i].first.second;
        if(Find(f) != Find(s)){
            Union(f,s);
            if(v[i].second == 0) cnt2++;
        }
    }
    cout << pow(cnt,2)-pow(cnt2,2);
}
