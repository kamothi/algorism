#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

bool cmp(pair<int,int> a , pair<int,int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll result = 0;
    ll comp = 0;
    vector<pair<ll,ll>> v;
    vector<ll> s;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back(make_pair(tmp1,tmp2));
    }
    sort(v.begin(),v.end(),cmp);
    comp = v[0].second;
    for(int i=1;i<n;i++){
        if(comp < v[i].second){
            s.push_back(v[i].second - comp);
            comp = v[i].second;
        }
        else{
            s.push_back(0);
        }
    }
    result += v[0].first*v[0].second;

    for(int i=1; i<v.size();i++){
        result += v[i].first * s[i-1];
    }
    cout << result;
}
