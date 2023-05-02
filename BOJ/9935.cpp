#include<iostream>
#include<string>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    string bomb;
    string temp = "";
    cin >> s;
    cin >> bomb;
    for(int i=0;i<s.size();i++){
        bool check = true;
        temp += s[i];
        if(temp.back() == bomb.back()){
            if(temp.size() < bomb.size()) continue;
            for(int j=0;j<bomb.size();j++){
                if(temp[temp.size() - bomb.size() + j] != bomb[j]){
                    check = false;
                    break;
                }
            }
            if(check) {
                for(int j=0;j<bomb.size();j++) temp.pop_back();
            }
        }
    }
    if(temp.empty()) {
        cout << "FRULA";
        return 0;
    }
    cout << temp;
}
