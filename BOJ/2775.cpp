#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[15][15];
    int t,k,n;
    for(int i=0;i<15;i++){
        arr[0][i] = i;
        arr[i][1] = 1;
    }
    for(int i=1;i<15;i++){
        for(int j=2;j<15;j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    cin >> t;
    while(t--){
        cin >> k >> n;
        cout << arr[k][n] << "\n";
    }
}
