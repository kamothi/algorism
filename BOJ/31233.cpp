#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    int result = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n-1;i++){
        result = max(result,min(v[i],v[i+1]));
    }
    for(int i=0;i<n-2;i++){
        vector<int> tmp;
        tmp.push_back(v[i]); tmp.push_back(v[i+1]); tmp.push_back(v[i+2]);
        sort(tmp.begin(),tmp.end());
        result = max(result,tmp[1]);
    }

    cout << result;
}
