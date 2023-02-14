#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    int arr[1000001];
    cin >> n >> m;

    for(int i=2;i<=m;i++) arr[i] = i;
    for(int i=2;i<=m;i++){
        if(arr[i]==0) continue;
        for(int j=i+i;j<=m;j+=i){
            arr[j] = 0;
        }
    }
    for(int i=n;i<=m;i++) {
        if(arr[i] != 0) cout << arr[i] << '\n';
    }

}
