#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<long long> v(n+1);
    vector<long long> sum(n+1);
    v[0]=0,sum[0] = 0;
    for(int i=1;i<=n;i++) {
        int tmp;
        cin >> tmp;
        v[i] = v[i-1] + tmp;
    }
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + (v[i]-v[i-1])*v[i-1];
    }

    while(m--){
        int l,r;
        cin >> l >> r;
        if(l==1) cout << sum[r] << "\n";
        else cout << sum[r] - (v[r]-v[l-1])*v[l-1] - sum[l-1] << "\n";

    }
}
