#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    cout << (n*n/2) + n*n%2;
}
