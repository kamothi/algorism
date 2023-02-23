#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[1001];
    int start,end;

    cin >> start >> end;
    int temp=1,sum=0;

    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            arr[temp] = i;
            if(temp > 1000) break;
            temp++;
        }
    }
    for(int i=start;i<=end;i++){
        sum += arr[i];
    }

    cout << sum;
}
