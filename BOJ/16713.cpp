#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,q;
    int temp;
    int result=0;
    int s,e;
    int sum[1000001];
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> temp;
        sum[i] = sum[i-1]^temp;
    }
    while(q--){
        cin >> s >> e;
        result ^= (sum[s-1]^sum[e]);
    }
    cout << result;
}
