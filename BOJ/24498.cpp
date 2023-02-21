#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n,Max=-1;
    long long arr[1000000];
    cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=1;i<n-1;i++){
        long long temp = min(arr[i-1],arr[i+1]);
        Max = max(Max,arr[i] + temp);
    }
    Max = max({Max, arr[0],arr[n-1]});
    cout << Max;
}
