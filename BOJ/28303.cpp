#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int ans =-200000000;
    int tmp = v[1] - k;
    //cout << tmp << "\n";
    for(int i=2;i<=n;i++){
        ans  = max(ans, v[i] - i*k - tmp);
        tmp = min(tmp, v[i] - i*k);
    }
    //cout << v[2] - 2*k - tmp << "\n";
    reverse(v.begin() + 1,v.end());
    tmp = v[1] - k;
    for(int i=2;i<=n;i++){
        ans  = max(ans, v[i] - i*k - tmp);
        tmp = min(tmp, v[i] - i*k);
    }
    cout << ans;
}
