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
    vector<int> copy;
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    copy = v;
    sort(copy.begin(),copy.end());
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        tmp[i] = lower_bound(copy.begin(), copy.end(), v[i]) - copy.begin();
    }

    for(int i=0;i<n;i++){
        if(tmp[i] != i){
            swap(tmp[i],tmp[tmp[i]]);
            result++;
            i--;
        }
    }
    cout << result;
}
