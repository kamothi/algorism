#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first > b.first;
    else return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    vector<pair<int,int>> v;
    int sum = 0;
    int result = 2147483647;
    bool check = false;
    int cnt= 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int tmp,tmp2;
        cin >> tmp >> tmp2;
        v.push_back({tmp,tmp2});
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++){
        sum += v[i].first; // 덩어리
        if(i != 0 && v[i-1].second == v[i].second){
            cnt += v[i].second;
        }
        else {
            cnt = 0;
        }
        if(sum >= m){
            check = true;
            result = min(result,cnt + v[i].second);
        }
    }
    if(check) cout << result;
    else cout << -1;


}
