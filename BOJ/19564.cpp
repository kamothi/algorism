#include<iostream>
#include<string>
using namespace std;
string s = "abcdefghijklmnopqrstuvwxyz";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt=0;
    string input;
    cin >> input;
    int i=0;
    while(1) {
        cnt++;
        for(int j=0;j<s.size();j++){
            if(i==input.size()-1 && input[i] == s[j]){
                cout << cnt;
                return 0;
            }
            if(input[i] == s[j]) {
                i++;
            }
        }
    }
}
