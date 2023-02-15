#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    vector<int> v;
    cin >> s;
    for(int i=0;i<s.size();i++) v.push_back(s[i] - '0');
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<v.size();i++) cout<<v[i];
}
