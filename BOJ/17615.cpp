#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string str;
    cin >> n;
    cin >> str;

    int r_cnt=0;
    int b_cnt=0;
    int total=5000001;

    for(int i=0;i<n;i++){
        if(str[i]=='R') r_cnt++;
        else b_cnt++;
    }
    for(int i=0;i<n;i++){
        if(str[i] == 'B'){
            total = min(total,(r_cnt-i));
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(str[i] == 'B'){
            int tmp = (r_cnt-n+i+1);
            total = min(total,tmp);
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(str[i] == 'R'){
            total = min(total,(b_cnt-i));
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(str[i] == 'R'){
            total = min(total,(b_cnt-n+i+1));
            break;
        }
    }
    cout << total;
}
