#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> nonPush;
bool check(int num){
    string s = to_string(num);
    for(char c :  s){
        for(int i=0;i<nonPush.size();i++){
            if(c - '0' == nonPush[i]) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int tmp;
        cin >> tmp;
        nonPush.push_back(tmp);
    }
    if(n==100) {
        cout << 0;
        return 0;
    }
    int result = abs(n-100);
    for(int i=0;i<1000000;i++){
        if(check(i)){
            int tmp = to_string(i).length() + abs(i-n);
            result = min(result,tmp);
        }
    }
    cout << result;
}
