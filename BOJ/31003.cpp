#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int x, int y){
    int temp;
    if(x < y){
        temp = x;
        x = y;
        y = temp;
    }

    int rest;
    while(y!=0){
        rest = x%y;
        x=y;
        y=rest;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[3000];
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        int tmp=-1;
        for(int j=i-1;j>=0;j--){
            if(gcd(arr[i],arr[j]) != 1){
                break;
            }
            if(arr[j] > arr[i]) tmp = j;
        }
        if(tmp == -1) continue;
        for(int j=i;j>tmp;j--){
            swap(arr[j],arr[j-1]);
        }
    }

    for(int i=0;i<n;i++) cout << arr[i] << " ";
}
