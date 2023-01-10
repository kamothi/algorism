#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    long long sum=0;
    int temp;
    long long max = 0;
    long long arr[100001] ={0,};
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        cin >> temp;
        arr[i] = temp + arr[i-1];
    }
    max = sum;
    for(int i=m;i<=n;i++){
        sum = arr[i] - arr[i-m];
        if(max < sum) max = sum;
    }
    cout << max;
}
