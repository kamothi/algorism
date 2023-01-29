#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, Max = -1;
    int arr[100001];
    int temp;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+n+1,greater<>());
    for(int i=1;i<=n;i++){
        temp = arr[i] + i +1;
        Max = max(temp,Max);
    }
    cout << Max;
}
