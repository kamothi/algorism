#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1002][10];
    int n;
    cin >> n;
    for(int i=0;i<10;i++){
        arr[1][i] = 1;
    }
    for(int i=2;i<=n+1;i++){
        for(int j=0;j<10;j++){
            if(j==0) {
                arr[i][j] = 1;
                continue;
            }
            arr[i][j] = (arr[i-1][j] + arr[i][j-1])%10007;
        }
    }
    cout << arr[n+1][9]%10007;
}
