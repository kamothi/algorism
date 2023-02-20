#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,cnt=0;

    cin >> n;
    int tmp=n;
    while(1){
        if(tmp == n && cnt != 0) break;
        tmp = (((tmp/10) + (tmp%10))%10) + (tmp%10)*10;
        cnt++;
    }
    cout << cnt;
}
