#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long v[100010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    long long result = -1e16,cnt=0;
    long long sum1=0,sum2=0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        sum1 += v[i];
    }
    sort(v,v+n,greater<long long>());
    for(int i=0;i<n;i++){
        cnt++;
        sum2 += v[i];
        sum1 -= v[i];
        result = max(result,sum2*cnt + sum1);
    }
    cout << result;
}
