#include<iostream>
#include<algorithm>
using namespace std;
bool com(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int arr[1000001];
    int temp[100000];
    cin >> n;
    fill_n(arr,1000001,-1000000);
    for(int i=0;i<n;i++) {
        cin >> temp[i];
        arr[temp[i]] = 0;
    }
    for(int i=1;i<=500000;i++){
        if(arr[i] == -1000000) continue;
        for(int j=i*2;j<=1000000;j+=i){
           if(arr[j] == -1000000) continue;
           else {
               arr[j]--;
               arr[i]++;
           }
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[temp[i]] << " ";
    }
}
