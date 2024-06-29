#include<iostream>

using namespace std;

typedef long long ll;

ll arr[100001];
ll tree[400001];
ll lazy[400001];

int n;

void init(int node, int s, int e){
    if(s == e) {
        tree[node] = arr[s];
        return;
    }

    int mid = (s+e)/2;

    init(node*2,s,mid);

    init(node*2+1,mid+1,e);

    tree[node] = tree[node*2]+tree[node*2+1];
}

void lazy_update(int node, int s, int e){
    if(lazy[node] != 0){
        tree[node] += (e-s+1)*lazy[node];
        if(s != e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update_query(int node, int s, int e, int l, int r, ll value){
    lazy_update(node, s, e);
    if(l > e || r < s) return 0;
    if(l <= s && e <= r){
        tree[node] += (e-s+1)*value;
        if(s != e){
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return 0;
    }

    int mid = (s+e)/2;
    ll nl = update_query(node*2,s,mid,l,r,value);
    ll nr = update_query(node*2+1,mid+1,e,l,r,value);
    return tree[node] = nl + nr;
}



ll query(int node, int s, int e, int idx){
    lazy_update(node,s,e);
    if(s == e) {
        return tree[node];
    }
    int mid = (s+e)/2;
    if(idx <= mid) return query(node*2, s, mid, idx);
    else return query(node*2 + 1, mid + 1, e, idx);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    int t;
    cin >> t;

    init(1,1,n);
    while(t--){
        int a;
        cin >> a;
        if(a == 1){
            int b,c,d;
            cin  >> b >> c >> d;
            update_query(1,1,n,b,c,d);
        }
        else{
            int idx;
            cin >> idx;
            cout << query(1,1,n,idx) << "\n";
        }
    }

}
