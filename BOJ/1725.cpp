#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll minTree[400000];
ll arr[100001];
ll result;
ll n;

void initMin(int node, int s, int e){
    if(s==e){
        minTree[node] = s;
        return;
    }
    else {
        int mid = (s + e) / 2;
        initMin(node * 2, s, mid);
        initMin(node * 2 + 1, mid + 1, e);

        if (arr[minTree[node * 2]] <= arr[minTree[node * 2 + 1]])
            minTree[node] = minTree[node * 2];

        else
            minTree[node] = minTree[node * 2 + 1];
    }
}

// 해당 구간의 최대 높이
ll Query(int node, int s, int e, int l, int r){
    if(e < l || r < s) return -1;
    if(l <= s && e <= r) return minTree[node];

    int mid = (s+e)/2;
    ll q1 = Query(node*2,s,mid,l,r);
    ll q2 = Query(node*2+1,mid+1,e,l,r);

    if (q1 == -1)
    return q2;
    else if (q2 == -1)
        return q1;
    else {
        if (arr[q1] <= arr[q2])
            return q1;
        else
            return q2;
    }

}

void getMax(int l, int r){
    ll idx = Query(1,0,n-1,l,r);
    ll h = arr[idx];
    ll area = (r-l+1)*h;
    result = max(result,area);

    if (l == r){ return; }
    if(l < idx){
        getMax(l,idx-1);
    }
    if(idx< r){
        getMax(idx+1,r);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    initMin(1,0,n-1);

    getMax(0,n-1);

    cout << result;

}
