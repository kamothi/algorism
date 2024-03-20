#include<iostream>
#include<math.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        double n;
        double result = 0;
        cin >> n;
        if(n ==1) {
            cout << 1 << "\n";
            continue;
        }
        for(double i = 1; i <= n; i++){
            result += log10(i);
        }
        cout << (int)result + 1 << "\n";
    }
}
