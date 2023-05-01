#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char s[51];
    vector<int> pa;
    int result = 0;
    vector<char*> v;
    cin >> s;
    char* token;
    token = strtok(s,"-");
    v.push_back(token);
    while(1){
        token =strtok(NULL,"-");
        if(token == NULL) break;
        v.push_back(token);
    }
    for(char* tmp : v){
        token = strtok(tmp,"+");
        int temp = 0;
        temp += stoi(token);
        while(1){
            token =strtok(NULL,"+");
            if(token == NULL) break;
            temp += stoi(token);
        }
        pa.push_back(temp);
    }
    result = pa[0];
    for(int i=1;i<pa.size();i++){
        result -= pa[i];
    }
    cout << result;

}
