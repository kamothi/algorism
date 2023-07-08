#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    string com;
    vector<int> v;
    getline(cin, input);
    getline(cin, com);
    int* fail = new int[com.size()];
    for(int i=0;i<com.size();i++) fail[i] = 0;

    int j = 0, cnt = 0;
    for (int i = 1; i < com.size(); i++) {
        while (j and com[i] != com[j]) j = fail[j - 1];
        if (com[j] == com[i]) fail[i] = ++j;
    }

    j = 0;
    for(int i=0;i<input.size();i++){
        while(j > 0 && input[i] != com[j]){
            j = fail[j - 1];
        }
        if(input[i] == com[j]){
            if(j == com.size() - 1){
                v.push_back(i-com.size() + 2);
                j = fail[j];
                cnt++;
            }
            else j++;
        }
    }
    cout << cnt << "\n";
    for(auto s : v) cout << s << " ";
}
