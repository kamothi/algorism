#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    int arr[1000000];
    for(int i=0;i<n;i++) cin >> arr[i];

    int s=0,e=0,cnt=0,ans=0;
    while (e<n) {
        if(cnt>k) {
            if(arr[s]%2==1) cnt--;
            s++;
        }
        else {
            if(arr[e]%2==1) cnt++;
            e++;
        }

        if(cnt<=k) ans=max(ans,e-s-cnt);
    }

    cout << ans << endl;

}
