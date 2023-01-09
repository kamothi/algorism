#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;
    int temp;
    int x[10],y[10];
    cin >> n >> a >>b;
    int a1,b1;
    for(int i=0;i<10;i++){
        cin >> x[i];
        cin >> y[i];
    }
    for(int i=0;i<(8-n);i++){
        a += x[i] * 3;
        b += x[i] * 3;
        if((6-x[i]) > y[i]) b += y[i] * 3;
        else b += (6-x[i]) * 3;
    }
    if(a >= 66 && b >= 130) cout << "Nice";
    else cout << "Nae ga wae";

}
