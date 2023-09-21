#include <iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    string s;
    int cnt = 0;
    stack<char> result;
    cin >> n >> k;
    cin >> s;

    for(int i=0;i<n;i++){
        if(result.empty()) result.push(s[i]);
        else{
            while(cnt < k && !result.empty() && result.top() - '0' < s[i] - '0'){
                cnt++;
                result.pop();
            }
            result.push(s[i]);
        }
    }


    string r;

    while(!result.empty()){
        r += result.top();
        result.pop();
    }

    reverse(r.begin(),r.end());

    for(int i=0;i<n-k;i++){
        cout << r[i];
    }



}
