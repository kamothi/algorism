#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t, cnt = 0;
    int arr[100];
    cin >> n >> t;
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=1;i<=t;i++){
        for(int j=0;j<n;j++){
            if(i%arr[j] == 0){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}
