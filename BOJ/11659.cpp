#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    int arr[100001];
    int sum[100001] = {0,};
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        if(i==1) {
            sum[i] = arr[i];
            continue;
        }
        sum[i] = sum[i-1] + arr[i];
    }

    while(m--){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        int result = sum[tmp2] - sum[tmp1-1];
        cout << result << "\n";
    }


}
