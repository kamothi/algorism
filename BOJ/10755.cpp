#include<iostream>

using namespace std;
int node[100001];

void make_set(int n){
    for(int i = 1; i <= n; i++) node[i] = i;
}

int find(int x) {
    if(x==node[x]) return x;
    return node[x] = find(node[x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    int g, p;
    cin >> g >> p;

    make_set(g);
    int n;
    for(int i=1;i<=p;i++){
        cin >> n;
        if(!find(n)) break;
        else{
            cnt++;
            node[find(n)]=find(find(n)-1);
        }
    }

    cout << cnt;
}
