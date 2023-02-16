#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cnt = 0;
    int arr[1001];
    int arr2[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr2[i];
    for(int i=2;i<=1000;i++) arr[i] = i;
    for(int i=2;i<=1000;i++){
        if(arr[i]==0) continue;
        for(int j=i+i;j<=1000;j+=i){
            arr[j] = 0;
        }
    }
    for(int i=0;i<n;i++) {
        if(arr[arr2[i]] == 1) continue;
        if(arr[arr2[i]] != 0) cnt++;
    }

    cout << cnt;
}
