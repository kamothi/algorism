#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,n;
    int arr[30000];
    char now='>';
    char check[30000];
    cin >> T;
    while(T--){
        int cnt = 1;
        now='>';
        cin >> n;
        for(int i=0;i<n;i++) cin >> arr[i];
        for(int i=0;i<n-1;i++) {
            if(arr[i] > arr[i+1]) check[i] = '>';
            else if(arr[i] < arr[i+1]) check[i] = '<';
        }
        for(int i=0;i<n-1;i++){
            if(now == check[i]) {
                cnt++;
                if(now == '>') now = '<';
                else now = '>';
            }
        }
        cout << cnt << "\n";
    }
}
