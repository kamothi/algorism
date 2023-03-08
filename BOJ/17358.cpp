#include<iostream>
#include<vector>

typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll l=1;
    for(int i=n-1;i>=1;i=i-2){
        l = l * i % 1000000007;
    }
    cout << l;
}
