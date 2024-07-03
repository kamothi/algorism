#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

int n;
long long arr[100001];
long long tree[400000];


void init(int node, int s, int e){
    if(s==e){
        tree[node] = s;
        return;
    }
    int mid = (s+e)/2;
    init(node*2,s,mid);
    init(node*2+1,mid+1,e);
    if(arr[tree[node*2]]<= arr[tree[node*2+1]]) tree[node] = tree[node*2];
    else tree[node] = tree[node*2+1];
}


ll query(int node, int s, int e, int l, int r){
    if(e < l || r < s) return -1;
    if(l <= s && e <= r) return tree[node];
    int mid = (s+e)/2;
    int left = query(node*2,s,mid,l,r);
    int right = query(node*2+1,mid+1,e,l,r);

    if(left == -1) return right;
    if(right == -1) return left;
    if(arr[left] <= arr[right]) return left;
    else return right;
}

ll solve(int s, int e){
    int idx = query(1,1,n,s,e);
    ll result = (e-s+1)*arr[idx];

    if(s <= idx - 1){
        ll left = solve(s,idx-1);
        result = max(result,left);
    }
    if(idx+1 <= e){
        ll right = solve(idx+1,e);
        result = max(result,right);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }

        init(1,1,n);
        ll result = solve(1,n);
        cout << result << "\n";

        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
    }

}
