#include<iostream>
#define ll long long int
#include<vector>
#include<algorithm>

using namespace std;

struct MealKit{
    ll s;
    ll l;
    ll o;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,g,k; // n 재료, g 세균수, k 버려도 되는 개수
    ll k_cnt=0;
    ll mid;
    ll result = 0;
    ll left=0, right=2e9;
    // 그 다음 줄 부터는 부패속도, 유통기한, 중요한 숫자인지(1 노중요, 0 중요 1은 빼기 가능)
    cin >> n >> g >> k;
    vector<MealKit> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].s >> v[i].l >> v[i].o;
        if(v[i].o) k_cnt++;
    }
    while(left <= right){
        vector<ll> o_g;
        ll sum = 0;
        mid = (left + right) / 2;
        for(int i=0;i<n;i++){
            ll temp = v[i].s * max(1ll,(mid-v[i].l));
            sum += temp;
            if(v[i].o) o_g.push_back(temp);
        }
        sort(o_g.begin(),o_g.end(),greater<>());
        for(int i=0;i<min(k,k_cnt);i++){
            sum -= o_g[i];
        }
        if(sum <= g){
            result = max(result,mid);
            left = mid + 1;
        }
        else{
            right = mid -1;
        }
    }
    cout << result;
}
