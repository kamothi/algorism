#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    string goal;
    int cnt[26] ={0,};
    stack<int> s;
    cin >> input;
    cin >> goal;

    for(int i=0;i<input.size();i++){
        for(int j=0;j<goal.size();j++){
            if(input[i] == goal[j]){
                if(j==0) cnt[0]++;
                else if(cnt[j-1] > cnt[j]) cnt[j]++;
                break;
            }
            else continue;
        }
    }
    cout << cnt[goal.size()-1];
}
