#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = 0;
    cin >> n;
    vector<int> v(n);
    vector<bool> check(n);
    vector<int> copy;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        check[i] = false;
    }
    copy = v;
    sort(copy.begin(),copy.end());
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        tmp[i] = lower_bound(copy.begin(), copy.end(), v[i]) - copy.begin();
    }
    for(int i=0;i<n;i++){
        if(check[i]) continue;
        int cnt = 0,x=i;
        while(!check[x]){
            check[x] = true;
            x = tmp[x];
            cnt++;
        }
        result += cnt - 1;
    }
    cout << result;
}
