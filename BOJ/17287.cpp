#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[10] ={0,};

    int Max = -1;
    int cnt = 0;
    string s;
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i] == '(') cnt +=1;
        else if(s[i] == ')') cnt -=1;
        else if(s[i] == '{') cnt += 2;
        else if(s[i] == '}') cnt -= 2;
        else if(s[i] == '[') cnt += 3;
        else if(s[i] == ']') cnt -= 3;
        else Max = max(cnt,Max);
    }
   
    cout << Max;
}
