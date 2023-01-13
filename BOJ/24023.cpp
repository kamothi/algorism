#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    int start = 0;
    int temp = 0;
    int arr[200000];

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++){
        if((arr[i] | k) <= k){
            temp = (temp | arr[i]);
            if(temp == k) {
                cout << start+1 << " " << i+1;
                return 0;
            }
        }
        else{
            temp=0;
            start = i+1;
        }
    }
    cout << -1;
    return 0;
}
