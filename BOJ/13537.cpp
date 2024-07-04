#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int n,m;
ll arr[100001];
vector<ll> tree[400000];


void init(int node, int s, int e, int idx, int value){
    if(idx < s || idx > e) return;
    tree[node].push_back(value);
    if (s != e) {
        int mid = (s + e) / 2;
        init(node * 2, s,mid, idx, value);
        init(node * 2 + 1, mid+1, e, idx, value);
    }
}


ll query(int node, int s, int e, int l, int r,int value){
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
    else{
        int mid = (s+e)/2;
        return query(node * 2, s, mid, l, r, value) +
               query(node * 2 + 1, mid+1, e, l, r, value);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        init(1, 1, n, i, tmp);
    }

    int range = 100001 * 4;
    for (int i = 1; i < range; ++i)
        sort(tree[i].begin(), tree[i].end());

    cin >> m;
    int i, j, k;
    while (m--) {
        cin >> i >> j >> k;
        cout << query(1, 1, n, i, j, k) << '\n';
    }
}
