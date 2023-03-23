#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t,n,m,k;
    long long cnt = 0,sum = 0,house_cnt=0;
    long long arr[100000];
    cin >> t;

    while(t--){
        cin >> n >> m >> k;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=0;i<n+m;i++){
            if(house_cnt < m){
                sum += arr[i%n];
                house_cnt++;
            }
            else{
                if(n == m){
                    if(sum < k) cnt++;
                    break;
                }
                if(sum < k) cnt++;
                sum += arr[i%n];
                sum -= arr[i-m];
            }
        }
        cout << cnt << "\n";
        cnt=0;
        sum=0;
        house_cnt = 0;
    }
}
