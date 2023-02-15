#include<iostream>
typedef long long ll;
using namespace std;

int main(){
    ll sum=0;
    ll s;
    int cnt = 0;
    cin >> s;
    for(int i=1;;i++){
        sum += i;
        cnt++;
        if(sum > s){
            cnt--;
            break;
        }
    }
    cout << cnt;
}
