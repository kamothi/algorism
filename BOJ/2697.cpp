#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str[1000];
    int n,t,num=-1;
    cin >> n;
    for(int i=0;i<n;i++) cin >> str[i];
    for(int i=0;i<n;i++){
        for(int j=str[i].size()-1;j>0;j--){
            if(str[i][j] > str[i][j-1]) {
                t = j - 1;
                num = str[i][j-1] - '0';
                break;
            }
        }
        if(num == -1) {
            cout<< "BIGGEST" << "\n";
            continue;
        }
        sort(str[i].begin() + t,str[i].end());
        for(int j=t;j<str[i].size();j++){
            if(str[i][j] - '0' > num){
                swap(str[i][j],str[i][t]);
                break;
            }
        }
        sort(str[i].begin()+t+1,str[i].end());
        cout << str[i] << "\n";
        num=-1;
    }
}
