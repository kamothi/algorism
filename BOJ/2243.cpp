#include<iostream>

using namespace std;
int tree[4000001] = {0,};
int arr[1000001] = {0,};

void update(int node, int s, int e, int idx, int value){
    if(e < idx || idx < s) return ;
    if(s==e) {
        tree[node] = tree[node] + value;
        return;
    }
    int mid = (s+e)/2;
    update(node*2,s,mid,idx,value);
    update(node*2+1,mid+1,e,idx,value);
    tree[node] = tree[node*2] + tree[node*2+1];
}


void query(int node, int s, int e, int cnt){ // 구하고자 하는 구간 [l,r]
    if(s==e){
        cout << s+1 << "\n";
        update(1,0,1000000,s,-1);
        return ;
    }
    int mid = (s+e)/2;
    if(cnt <= tree[node*2]) query(node*2,s,mid,cnt);
    else query(node*2+1,mid+1,e,cnt-tree[node*2]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 사탕 상자에 손을 댄 횟수
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        if(a==1){
            query(1,0,1000000,b);
        }
        else{
            int c;
            cin >> c; // b는 넣을 맛(arr의 인덱스), c는 갯수 양수면 그만큼 넣고 음수면 그만큼 뺀다.
            update(1,0,1000000,b-1,c);
        }
    }
}
