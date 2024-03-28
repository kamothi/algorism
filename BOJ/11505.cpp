#include<iostream>

using namespace std;

typedef long long ll;
ll MOD = 1000000007;

ll tree[4000000];
ll arr[4000001];

void init(int node, int s, int e){
    if(s==e){
        tree[node] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    init(node*2,s,mid);
    init(node*2+1,mid+1,e);
    tree[node] = tree[node*2] * tree[node*2+1] % MOD;
}


ll query(int node, int s, int e, int l, int r){
    if(e < l || r < s) return 1;
    if(l <= s && e <= r) return tree[node];
    int mid = (s+e)/2;
    return query(node*2,s,mid,l,r) * query(node*2+1,mid+1,e,l,r) % MOD;
}


void update(int node, int s, int e, int idx, ll value){
    if(e < idx || idx < s) return;
    if(s == e) {
        tree[node] = value;
        return;
    }
    int mid = (s+e)/2;
    update(node*2,s,mid,idx,value);
    update(node*2+1,mid+1,e,idx,value);
    tree[node] = tree[node*2] * tree[node*2+1] % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m, k;
    cin >> n >> m >> k;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    init(1,1,n);

    for(int i=0;i<m+k;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1,1,n,b,c);
        }
        else{
            cout << query(1,1,n,b,c) % MOD << "\n";
        }
    }

}
