#include<iostream>

using namespace std;

int node[1000001];

void set(){
    for(int i=0;i<1000001;i++) node[i] = i;
}

int Find(int i) {
    if(node[i] == i) return i;
    node[i] = Find(node[i]);
    return (node[i]);
}
void Union(int a, int b) {
    node[Find(a)] = Find(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // n개의 집합, m개의 연산
    int n,m;
    cin >> n >> m;

    set();

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;

        if (a == 0){
            Union(b,c);
        }
        else{
            if(Find(b) == Find(c)) cout<< "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }



}
