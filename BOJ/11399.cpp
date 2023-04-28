#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,sum=0;
    int arr[1000];
    int time[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    time[0] = arr[0];
    sum += time[0];
    for(int i=1;i<n;i++){
        time[i] = time[i-1] + arr[i];
        sum += time[i];
    }
    cout << sum;
}
