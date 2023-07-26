#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    if(n%2 == 1){
        cout << -1;
        return 0;
    }
    int cnt = 0;
    while(1){
        if(cnt %2 == 0) cout << n-cnt << " ";
        else cout << cnt << " ";
        cnt++;
        if(cnt == n) break;
    }

}
