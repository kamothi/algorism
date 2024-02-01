#include<iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    int n,k;
    bool flag = false;
    string s;
    int lr = 0, ud = 0;

    cin >> n >> k;
    cin >> s;

    int t;
    if(s.size() < k) t = s.size();
    else t = k;
    while(t--){
        for(int i=0;i<s.size();i++){
            if(s[i] == 'R') lr++;
            else if(s[i] == 'L') lr--;
            else if(s[i] == 'U') ud++;
            else ud--;

            if(lr == 0 && ud == 0) flag = true;
        }
    }

    if(flag) cout << "YES";
    else cout << "NO";
}
