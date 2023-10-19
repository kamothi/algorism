#include<iostream>

using namespace std;

int arr[500000] = {0,};
int tree[2000000] = {0,};
int lazy[2000000] = {0,};

int init(int node, int s, int e){
    if(s == e) {
        return tree[node] = arr[s];
    }
    int mid = (s+e)/2;
    return tree[node] = init(node*2,s,mid)^init(node*2+1,mid+1,e);
}

void push(int node, int s, int e){
    if(!lazy[node]) return;
    if((e-s+1)%2!=0){
        tree[node]^=lazy[node];
    }
    if(s != e){
        lazy[node*2] ^= lazy[node];
        lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int s, int e, int l, int r, int value){
    push(node, s, e);
    if(e < l || r < s) return ;
    if (l <= s && e <= r){
        lazy[node] ^= value;
        push(node, s, e);
        return;
    }
    int mid = (s + e) / 2;
    update(node*2, s, mid, l, r, value);
    update(node*2+1, mid+1, e, l, r, value);
    tree[node] = tree[node*2]^tree[node*2+1];
}
int query(int node, int s, int e, int l, int r){ push(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    int n1 = query(node*2, s, mid, l, r);
    int n2 = query(node*2+1, mid+1, e, l, r);
    return n1^n2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> m;
    int tmp,i,j,k;
    init(1,0,n-1);
    while(m--){
        cin >> tmp;
        if(tmp == 1){
            cin >> i >> j >> k;
            update(1,0,n-1,i,j,k);
        }
        else{
            cin >> i >> j;
            int result = query(1,0,n-1,i,j);
            cout << result << "\n";
        }
    }
}
