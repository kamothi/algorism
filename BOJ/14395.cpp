#include<iostream>
#include<queue>
#include<set>

using namespace std;

long long s,t;
string result;
set<long long> visited;

void solve(){
    queue<pair<string,long long>> q;
    q.push({"",s});
    visited.insert(s);

    while(!q.empty()){
        string tmp1 = q.front().first;
        long long tmp2 = q.front().second;
        q.pop();

        if(tmp2 == t){
            cout << tmp1;
            return;
        }

        if (visited.find(tmp2 * tmp2) == visited.end()) {
            visited.insert(tmp2*tmp2);
            q.push({tmp1+"*",tmp2*tmp2});
        }

        if (visited.find(tmp2 * 2) == visited.end()) {
            visited.insert(tmp2*2);
            q.push({tmp1+"+",tmp2*2});
        }
        if (visited.find(tmp2 - tmp2) == visited.end()) {
            visited.insert(tmp2-tmp2);
            q.push({tmp1+"-",tmp2-tmp2});
        }
        if (tmp2 != 0  && visited.find(tmp2/tmp2) == visited.end()) {
            visited.insert(tmp2/tmp2);
            q.push({tmp1+"/",tmp2/tmp2});
        }

    }

    cout << -1;
}

// s의 값을 t로 바꾸기
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> t;

    // s와 t가 같은 경우는 0을 출력, 못 만들면 -1, 가능하면 사전순으로 앞서는 방법
    if(s == t) {
        cout << 0;
        return 0;
    }

    solve();


    return 0;


}
