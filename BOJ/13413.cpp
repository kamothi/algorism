#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,n;
    string s1,s2;
    cin >> t;

    while(t--){
        int total;
        int b_cnt = 0;
        int w_cnt = 0;
        cin >> n;
        cin >> s1 >> s2;

        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                ('B' == s1[i]) ? b_cnt++ : w_cnt++;
            }
        }
        total = (b_cnt >= w_cnt) ? b_cnt : w_cnt;
        cout << total << "\n";
    }
}
