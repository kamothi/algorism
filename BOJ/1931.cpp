#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,cnt=1,t;
    vector<pair<int,int>> v;
    cin >> n;

    for(int i=0;i<n;i++) {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1,temp2));
    }

    sort(v.begin(),v.end(), compare);
    t=0;
    for(int i=1;i<n;i++){
        if(v[t].second <= v[i].first){
            cnt++;
            t=i;
        }
    }

    cout << cnt;
}
