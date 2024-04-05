#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

ll solve(ll n, ll k){
    ll ret;
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    ret = solve(n, k / 2);
    ret = ret * ret;
    ret %= MOD;
    if (k % 2)
        ret *= n;
    return ret % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll sum = 0;
    cin >> n;
    ll arr[300000];
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr,arr+n);

    for (int i = 0; i < n; i++) {
        sum += arr[i] * (solve(2, i) + MOD - solve(2, (ll)n - i - 1)) % MOD;
        sum %= MOD;
    }

    cout << sum;


}
