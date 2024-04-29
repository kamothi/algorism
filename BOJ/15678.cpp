#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int n,d;
ll arr[100001];
ll tree[400000];



ll query(int node, int s, int e, int qs, int qe) {
    if (e < qs || qe < s) return -1e9;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s+e)/2;
    return max(query(2 * node, s, mid, qs, qe), query(2 * node + 1, mid + 1, e, qs, qe));
}

void update(int node, int s, int e, int idx, ll num) {
    if (e < idx || idx < s) return;
    if (s == e) {
        tree[node] = num;
        return;
    }
    int mid = (s + e) >> 1;
    update(2 * node, s, mid, idx, num);
    update(2 * node + 1, mid + 1, e, idx, num);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d;

    ll result = -1e9;

    for(int i=0;i<n;i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        arr[i] = max(arr[i], query(1, 0, n, max(0, i - d), i - 1) + arr[i]);
        result = max(result, arr[i]);
        update(1, 0, n, i, arr[i]);
    }
    cout << result;
}
