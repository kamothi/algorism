#include<iostream>

using namespace std;

int main(){
    int n,cnt=2;
    int Max = 0;
    int max_arr[30000];
    int arr[30000];
    cin >> n;
    arr[0] = n;
    for(int i=1;i<=n;i++){
        arr[1] = i;
        while(1){
            arr[cnt] = arr[cnt-2] - arr[cnt-1];
            if(arr[cnt] < 0) break;
            cnt++;
        }
        if(cnt > Max){
            Max = cnt;
            for(int j=0;j<cnt;j++) max_arr[j] = arr[j];
        }
        cnt =2;
    }
    cout << Max << "\n";
    for(int i=0;i<Max;i++) cout << max_arr[i] << " ";
}
