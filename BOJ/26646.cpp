#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int arr[50000];
    int result =0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n-1;i++){
        result += 2*pow(arr[i],2) + 2*pow(arr[i+1],2);
    }
    cout << result;
}
