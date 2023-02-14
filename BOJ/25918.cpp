#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<char> s1;
    int n, Max=0, cnt =0;
    string s;
    cin >> n;
    cin >> s;

    for(int i=0;i<n;i++){
        if(s[i] == '('){
            if(s1.empty() || s1.top() == '(') s1.push('(');
            else if(s1.top() == ')') s1.pop();
        }
        else{
            if(s1.empty() || s1.top() == ')') s1.push(')');
            else if(s1.top() == '(') s1.pop();
        }
        cnt = s1.size();
        Max = max(Max,cnt);
    }
    if(!s1.empty()) {
        cout << -1;
        return 0;
    }

    cout << Max;
}
