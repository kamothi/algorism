#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cnt=0,temp,Max=-1;
    int arr[30000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++){
        temp = arr[i];
        cnt=0;
        for(int j=i+1;j<n;j++){
            if(temp < arr[j]) {
                break;
            }
            else cnt++;
        }
        Max = max(Max,cnt);
    }
    cout << Max;
}
