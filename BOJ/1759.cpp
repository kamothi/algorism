#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int l, c;
vector<char> v(15);

bool check(string password){
    int j = 0, m = 0;
    for(char c : password){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') m++;
        else j++;
    }
    return (j >= 2 && m >= 1);
}

void find(string password,int i){
    if(password.length() == l){
        if(check(password)){
            cout << password << "\n";
        }
        return;
    }
    
    if(i == c) return;
    find(password + v[i],i+1);
    find(password, i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 서로 다른 l개의 문자열, c개의 문자 종류
    
    cin >> l >> c;

    for(int i=0;i<c;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.begin()+c);

    find("",0);



}
