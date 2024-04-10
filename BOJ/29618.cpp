#include<iostream>

using namespace std;

int node[100002];
int color[100001];

void make_set(int n){
    for(int i = 0; i < n; i++) node[i] = i;
}

int Find(int i) {
    if(node[i] == i) return i;
    return node[i] = Find(node[i]);
}


void Union(int a, int b) {
    node[Find(a)] = Find(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    make_set(100002);

    for(int i=0;i<m;i++){
        int a,b,x;
        cin >> a >> b >> x;
        for(int j=a;j<=b;j++){
            if(Find(j) != j){
                // 색칠된 값
                j = Find(j) - 1;
            }
            else{
                Union(j,j+1);
                color[j] = x;
            }
        }
    }

    for(int i=1;i<=n;i++) cout << color[i] << " ";
}
