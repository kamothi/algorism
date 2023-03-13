#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    bool check_p = false; //전체 문자열이 팰린드롬인지 확인 , true면 팰린드롬이 아니다
    bool check_all = false;
    cin >> s;

    for(int i=0;i<s.size()/2;i++){
        if(s[i] == s[s.size()-1 - i]) continue;
        else{
            check_p = true;
            break;
        }
    }
    if(check_p) {
        cout << s.size();
        return 0;
    }
    else{
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == s[i+1]) continue;
            else{
                check_all = true;
                break;
            }
        }
        if(check_all){
            cout << s.size()-1;
            return 0;
        }
        else{
            cout << -1;
            return 0;
        }
    }
}
