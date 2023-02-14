#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cnt = 0;
    string s;
    stack<char> s1,s2;
    char temp;
    cin >> n;
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i] == 'S') s1.push(s[i]);
        else if(s[i] == 'K'){
            if(s1.size()){
                cnt++;
                s1.pop();
            }
            else break;
        }
        else if(s[i] == 'L') s2.push(s[i]);
        else if(s[i] == 'R'){
            if(s2.size()){
                cnt++;
                s2.pop();
            }
            else break;
        }
        else cnt++;
    }
    cout << cnt;
}
