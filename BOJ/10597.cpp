#include<iostream>
#include<vector>

using namespace std;

int scale;
string s;
vector<int> result;
bool check = false;
bool visited[51];

void solve(int idx, int n){

    if(n == scale){
        for(int i=0;i<scale;i++) cout << result[i] << " ";
        check = true;
        return;
    }

    // 한자리 수 확인
    int tmp = s[idx] - '0';
    if(tmp != 0 && !visited[tmp] && !check){
        visited[tmp] = true;
        result.push_back(tmp);
        solve(idx+1,n+1);
        result.pop_back();
        visited[tmp] = false;
    }

    // 두자리 수 확인
    if(idx+1 < s.size()){
        tmp = tmp*10 + s[idx+1] - '0';
        if(tmp <= scale && !visited[tmp] && !check){
            visited[tmp] = true;
            result.push_back(tmp);
            solve(idx+2,n+1);
            result.pop_back();
            visited[tmp] = false;
        }
    }

}

int main(){
    cin >> s;

    if(s.size() < 10) scale = s.size();
    else scale = 9 + (s.size()-9)/2;
    solve(0,0);

}
