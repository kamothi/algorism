#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,a,d;
    int cnt = 0;
    int temp;
    cin >> n >> a >> d;

    int arr[20001];
    for(int i=0;i<n;i++) cin >> arr[i];

    temp = a;
    for(int i=0;i<n;i++){
        if(temp == arr[i]){
            cnt++;
            temp += d;
        }
    }
    cout << cnt;
}
