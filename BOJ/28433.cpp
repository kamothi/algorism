#include<iostream>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t,n;
    cin >> t;

    while(t--){
        int cnt = 0;
        cin >> n;
        ll arr[200000];
        for(int i=0;i<n;i++) cin >> arr[i];

        ll sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                if(sum >= 0){
                    sum = arr[i];
                    cnt++;
                }
                else{
                    if(sum + arr[i] > 0){
                        cnt +=2;
                        sum += arr[i];
                    }else{
                        sum = arr[i];
                        cnt +=1;
                    }
                }
            }
            else if(arr[i] < 0){
                if (sum >= 0)
                    if (sum + arr[i] > 0)
                        sum += arr[i];
                    else{
                        cnt--;
                        sum = arr[i];
                    }
                else sum+=arr[i];
            };
        }

        if(cnt > 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";

    }
}
