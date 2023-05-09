#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long result=0;
    int n,k; // 주전자,친구
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    long long l=0,r=arr[n-1],mid;
    while(l<=r){
        long long tmp = 0;
        mid = (l+r)/2;
        if(mid == 0) {
            l = mid + 1;
            continue;
        }
        for(int i=0;i<n;i++){
            tmp += arr[i]/mid;
        }
        if(tmp >= k) {
            l = mid + 1;
            result = mid;
        }
        else r = mid -1;
    }
    cout << result;

}
