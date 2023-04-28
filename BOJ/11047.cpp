#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    int sum = 0;
    int arr[10];
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];

    while(1){
        if(k == 0) break;
        for(int i=n-1;i>=0;i--){
            if(k/arr[i] > 0){
                sum += k/arr[i];
                k = k%arr[i];
            }
        }
    }
    cout << sum;
}
