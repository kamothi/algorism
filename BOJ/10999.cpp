#include<iostream>

using namespace std;
typedef long long ll;

ll arr[1000000];
ll tree[4000000];
ll lazy[4000000];

ll init(int node, int s, int e){
    if(s == e) {
        return tree[node] = arr[s];
    }
    int mid = (s+e)/2;
    return tree[node] = init(node*2,s,mid) + init(node*2+1,mid+1,e);
}

void push(int node, int s, int e){
    if(!lazy[node]) return;
    tree[node] += lazy[node]*(e-s+1);
    if(s != e){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int s, int e, int l, int r, ll value){
    push(node, s, e);
    if(e < l || r < s) return ;
    if (l <= s && e <= r){
        lazy[node] += value;
        push(node, s, e);
        return;
    }
    int mid = (s + e) / 2;
    update(node*2, s, mid, l, r, value);
    update(node*2+1, mid+1, e, l, r, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll query(int node, int s, int e, int l, int r){
    push(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    ll n1 = query(node*2, s, mid, l, r);
    ll n2 = query(node*2+1, mid+1, e, l, r);
    return n1+n2;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    init(1,0,n-1);
    for(int i=0;i<m+k;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            ll d;
            cin >> d;
            update(1,0,n-1,b-1,c-1,d);
        }
        else{
            ll result = query(1,0,n-1,b-1,c-1);
            cout << result << "\n";
        }
    }
}
