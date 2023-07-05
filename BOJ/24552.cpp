#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int Lcnt = 0;
    int Rcnt = 0;
    int tmp = 0;
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i] == '(') {
            Lcnt++;
            tmp++;
        }
        else if(s[i] == ')'){
            Rcnt++;
            tmp--;
        }
        if(tmp < 0){
            cout << Rcnt;
            return 0;
        }
        if(tmp == 0){
            Lcnt = 0;
        }
    }
    cout << Lcnt;
}
