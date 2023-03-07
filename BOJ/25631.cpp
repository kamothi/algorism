#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, Max = 1;
    int arr[1000];
    int temp=1;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,greater<>());
    for(int i=0;i<n-1;i++){
        if(arr[i] == arr[i+1]) temp++;
        else{
            Max = max(Max,temp);
            temp =1;
        }
        if(i==n-2) Max = max(Max,temp);
    }
    cout << Max;
}
