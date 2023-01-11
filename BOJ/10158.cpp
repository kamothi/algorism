#include<iostream>

using namespace std;

int main(){
    int w,h,p,q,t;
    int p1=0,q1=0;

    cin >> w >> h >> p >> q >> t;

    p1 += (p+t);
    q1 += (q+t);

    p1 = p1 % (2 * w);
    q1 = q1 % (2 * h);

    if(p1 > w){
        p1 = w-(p1%w);
    }
    if(q1 > h){
        q1 = h - (q1%h);
    }
    cout << p1 << " " << q1;
}
