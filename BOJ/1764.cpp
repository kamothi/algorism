#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string,int> map;
    int n,m,cnt=0;
    string temp;
    vector<string> s;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> temp;
        map.insert({temp,1});
    }
    for(int i=0;i<m;i++){
        cin >> temp;
        if(map.find(temp) != map.end()){
            s.push_back(temp);
        }
    }
    sort(s.begin(),s.end());
    cout << s.size() << '\n';
    for(int i=0;i<s.size();i++) cout << s[i] << '\n';
}
