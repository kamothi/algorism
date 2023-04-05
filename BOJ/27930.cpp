#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    bool yonsei[6] = {false,},korea[5] = {false,};
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'Y') yonsei[0] = 1;
        else if(s[i] == 'K') korea[0] = 1;
        else if(s[i] == 'O') {
            if(yonsei[0] == 1) yonsei[1] = 1;
            if(korea[0] == 1) korea[1] = 1;
        }
        else if(s[i] == 'N'){
            if(yonsei[1] == 1) yonsei[2] = 1;
        }
        else if(s[i] == 'S'){
            if(yonsei[2] == 1) yonsei[3] = 1;
        }
        else if(s[i] == 'R') {
            if(korea[1] == 1) korea[2] = 1;
        }
        else if(s[i] == 'E'){
            if(yonsei[3] == 1) yonsei[4] = 1;
            if(korea[2] == 1) korea[3] = 1;
        }
        else if(s[i] == 'I'){
            if(yonsei[4] == 1) yonsei[5] = 1;
        }
        else if(s[i] == 'A'){
            if(korea[3] == 1) korea[4] = 1;
        }
        if(yonsei[5] == 1){
            cout << "YONSEI";
            return 0;
        }
        if(korea[4] == 1){
            cout << "KOREA";
            return 0;
        }
    }
}
