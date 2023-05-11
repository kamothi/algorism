#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    long long l,r;
    long long mid,result;
    l=1;
    r = *max_element(v.begin(), v.end());
    while(l<=r){
        mid = (l+r)/2;
        int cnt = 0;
        for(int i=0;i<n;i++){
            int tmp = v[i]/mid;
            cnt += tmp;
        }
        if(cnt < k){
            r = mid -1;
        }
        else{
            l = mid + 1;
            result = mid;
        }
    }

    cout << result;

}
