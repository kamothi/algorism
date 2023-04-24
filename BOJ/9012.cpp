#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        bool check = false;
        stack<char> c;
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') c.push('(');
            else if(s[i] == ')' && !c.empty()) c.pop();
            else {
                check = true;
                break;
            }
        }
        if(check || !c.empty()) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}
