#include<iostream>

using namespace std;

int a[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,b,c;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> b >> c;

    long long sum = 0;

    for(int i=0;i<n;i++){
        a[i] -= b;
        sum++;
        if(a[i] <= 0){
            continue;
        }
        if(a[i]%c == 0){
            sum += a[i]/c;
        }else{
            sum += a[i]/c + 1;
        }
    }
    cout << sum;

}
