#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

pair<ll,ll> f[100000];

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return a.first > b. first;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,d;//친구수와 최소차
    ll result = 0;
    int left = 0, right = 0;
    ll temp = 0;
    cin >> n >> d;
    for(int i=0;i<n;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        f[i] = make_pair(tmp1,tmp2);
    }
    sort(f,f+n,cmp);

    while(right < n){
        if((f[left].first-f[right].first) >= d) temp -= f[left++].second;
        else temp += f[right++].second;
        result = max(result,temp);
    }

    cout << result;

}
