#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int result;
    int n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int,int>> v(n);
        result = 0;
        for(int i=0;i<n;i++){
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(),v.end());
        while(!v.empty()){
            int w = -10000;
            for(auto t=v.begin();t!=v.end();){
                if(w <= t->second){
                    w = t->second;
                    t = v.erase(t);
                }
                else{
                    t++;
                }
            }
            result++;
        }
        cout << result << "\n";
    }
}
