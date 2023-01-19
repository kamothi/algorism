#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t,n,a,b;
    int cnt=0;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        long long temp = min(a,b);
        long long weight = pow(2,n);
        while(1){
            if(weight == temp) {
                cout << cnt << "\n";
                cnt =0;
                break;
            }
            else if(weight < temp){
                temp = temp - weight;
                cnt++;
                weight = weight/2;
            }
            else {
                weight = weight/2;
                cnt++;
            }
        }
    }
}
