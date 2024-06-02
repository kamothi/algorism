#include<iostream>

using namespace std;

int n;
long long k;
int t[200001][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for(int i=1;i<=n;i++){
        int l,r;
        cin >> l >> r;

        t[i][0] = l;
        t[i][1] = r;
    }
    cin >> k;
    long long cur = 1;

    while(1){
        if(t[cur][0] == -1 && t[cur][1] == -1) break;
        else if(t[cur][0] == -1 && t[cur][1] != -1) cur = t[cur][1];
        else if(t[cur][0] != -1 && t[cur][1] == -1) cur = t[cur][0];
        else{
            if(k%2 == 0) {
                cur = t[cur][1];
                k /= 2;
            }
            else {
                cur = t[cur][0];
                k = (k+1)/2;
            }
        }
    }
    cout << cur;
}
