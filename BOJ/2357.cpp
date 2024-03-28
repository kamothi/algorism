#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll minTree[400000];
ll maxTree[400000];
ll arr[100001];

void initMin(int node, int s, int e){
    if(s==e){
        minTree[node] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    initMin(node*2,s,mid);
    initMin(node*2+1,mid+1,e);
    minTree[node] = min(minTree[node*2],minTree[node*2+1]);
}


void initMax(int node, int s, int e){
    if(s==e){
        maxTree[node] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    initMax(node*2,s,mid);
    initMax(node*2+1,mid+1,e);
    maxTree[node] = max(maxTree[node*2],maxTree[node*2+1]);
}


ll minQuery(int node, int s, int e, int l, int r){
    if(e < l || r < s) return 1e9+1;
    if(l <= s && e <= r) return minTree[node];
    int mid = (s+e)/2;
    return min(minQuery(node*2,s,mid,l,r),minQuery(node*2+1,mid+1,e,l,r));
}

ll maxQuery(int node, int s, int e, int l, int r){
    if(e < l || r < s) return -1;
    if(l <= s && e <= r) return maxTree[node];
    int mid = (s+e)/2;
    return max(maxQuery(node*2,s,mid,l,r),maxQuery(node*2+1,mid+1,e,l,r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> arr[i];
    initMin(1,1,n);
    initMax(1,1,n);

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        ll MIN = minQuery(1,1,n,a,b);
        ll MAX = maxQuery(1,1,n,a,b);
        cout << MIN << " " << MAX << "\n";
    }

}
