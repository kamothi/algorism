#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r,c,n;
    cin >> r >> c >> n;
    if(r % 2 == 0 || c % 2 == 0) cout << 1;
    else{
        if(n == 1) cout << 1;
        else cout << 0;
    }
}
