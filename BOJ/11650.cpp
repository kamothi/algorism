#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> arr;

    for(int i=0;i<n;i++){
        int tmp,tmp2;
        cin >> tmp >> tmp2;
        arr.push_back(make_pair(tmp,tmp2));
    }

    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<n;i++) cout << arr[i].first << " " << arr[i].second << "\n";



}
