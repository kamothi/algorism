#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,Max=-1,s;
    int arr[1000];
    int temp;
    cin >> n;
    cin >> arr[0];
    s=arr[0];
    for(int i=1;i<n;i++){
        cin >> arr[i];
        if(arr[i] <= arr[i-1]){
            temp = arr[i-1] - s;
            Max = max(Max,temp);
            s = arr[i];
        }
        if(i==(n-1) && arr[i] > arr[i-1]){
            temp = arr[i] - s;
            Max = max(Max,temp);
        }
    }
    cout << Max;


}
