#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int arr[100000];
    int cnt1=1, cnt2=1;
    int MAX=1;
    int answer = 1;

    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n-1;i++){
        if(arr[i] >= arr[i+1]) cnt1++;
        else cnt1 = 1;
        if(arr[i] <= arr[i+1]) cnt2++;
        else cnt2 = 1;
        MAX =max(cnt1,cnt2);
        answer = max(answer,MAX);
    }
    cout << answer;
}
