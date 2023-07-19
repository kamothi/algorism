#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    long long sum = 0;
    long long current = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++){
        current += v[i].second;
        if((sum+1)/2 <= current) {
            cout << v[i].first;
            return 0;
        }
    }
}
