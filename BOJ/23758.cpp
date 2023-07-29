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
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<(n+1)/2;i++){
        while(v[i] != 1){
            v[i] = v[i] / 2;
            result++;
        }
    }
    cout << ++result;
}
