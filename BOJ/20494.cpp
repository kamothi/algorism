#include<iostream>
#include<string>
using namespace std;

int main(){
    int n ,cnt=0;
    string len;
    cin >> n;
    while(n--) {
       cin >> len;
       cnt+=len.size();
    }
    cout << cnt;
}
