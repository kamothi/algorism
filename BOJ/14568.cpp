#include<iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int a,b,c;
    cin >> n;
    int cnt = 0;

    for(int i=2;i<n;i=i+2){
        int r = n-i;
        for(int j=1;j<r;j++){
            if(j+2 <= r-j) cnt++;
        }
    }

    cout << cnt;
}
