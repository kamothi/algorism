#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int tree[2000000] = {0,};
vector<int> v(500000);
vector<int> v2(500000); // 카피본

int query(int node, int s, int e, int l, int r){ // 구하고자 하는 구간 [l,r]
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tree[node];
    int mid = (s+e)/2;
    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}

void update(int node, int s, int e, int idx, int value){
    if(e < idx || idx < s) return ;
    if(s==e) {
        tree[node] = value;
        return;
    }
    int mid = (s+e)/2;
    update(node*2,s,mid,idx,value);
    update(node*2+1,mid+1,e,idx,value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 달리기 선수
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        v2[i] = v[i];
    }

    sort(v2.begin(),v2.begin()+n);

    for (int i = 0; i < n; i++){
        int l = lower_bound(v2.begin(), v2.begin() +n, v[i]) - v2.begin();
        int result = query(1,0,n-1,l,n-1) + 1;
        cout << result << "\n";
        update(1,0,n-1,l,1);
    }

}
