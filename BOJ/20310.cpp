#include<iostream>

using namespace std;

// 0과 1로 이루어진 문자열, 0과 1의 개수는 각각 모두 짝
// 절반의 0과 절반의 1을 삭제하여
// 사전순으로 가장 빠르게
// 길이는 500이하
bool check[500];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int zero = 0;
    int one = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '0') zero++;
        else one++;
    }

    zero /=2;
    one /=2;
    for(int i=0;i<s.size();i++){
        if(one > 0 && s[i] == '1') {
            check[i] = 1;
            one--;
        }
    }

    for(int i=s.size()-1;i>=0;i--){
        if(zero > 0 && s[i] == '0') {
            check[i] = 1;
            zero--;
        }
    }

    for(int i=0;i<s.size();i++) if(!check[i]) cout << s[i];


}
