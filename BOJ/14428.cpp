#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

pair<ll,ll> minTree[400000];
ll arr[100001];

void initMin(int node, int s, int e){
    if(s==e){
        minTree[node] = {arr[s], s};
        return;
    }
    int mid = (s+e)/2;
    initMin(node*2,s,mid);
    initMin(node*2+1,mid+1,e);
    minTree[node] = min(minTree[node*2],minTree[node*2+1]);
}

pair<ll,ll> min(pair<ll,ll> &a,pair<ll,ll> &b) {
    if (a.first < b.first) return a;
    if (a.first == b.first) {
        if (a.second < b.second) return a;
        else return b;
    }
    else return b;
}



pair<ll,ll> minQuery(int node, int s, int e, int qs, int qe) {
    if (e < qs || qe < s) return {1e9, 1e9};
    if (qs <= s && e <= qe) return minTree[node];
    int mid = (s + e) >> 1;
    return min(minQuery(2 * node, s, mid, qs, qe), minQuery(2 * node + 1, mid + 1, e, qs, qe));
}

void update(int node, int s, int e, int idx, int num) {
    if (e < idx || idx < s) return;
    if (s == e) {
        minTree[node] = {num, idx};
        return;
    }
    int mid = (s + e) >> 1;
    update(2 * node, s, mid, idx, num);
    update(2 * node + 1, mid + 1, e, idx, num);
    minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) cin >> arr[i];

    initMin(1, 0, 1e5);

    int q;
    cin >> q;
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(1, 0, 1e5, a, b);
        } else {
            cout << minQuery(1, 0, 1e5, a, b).second << "\n";
        }
    }
}
