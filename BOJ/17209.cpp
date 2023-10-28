#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v[2001];
vector<vector<int>> g(2001);
int old = 0, young = 0;

void dfs(int cur, int color){
    v[cur] =color;
    int nxt_color;
    if(color == 1){
        nxt_color = 2;
        young++;
    }
    else{
        nxt_color = 1;
        old++;
    }
    for(int nxt : g[cur]){
        if (v[nxt] == color) return;
        if (v[nxt]) continue;
        dfs(nxt, nxt_color);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j] == '1') {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }


    for(int i=0;i<n;i++){
        if(!v[i]){
            dfs(i,1);
            result += max(young,old);
            young =0, old = 0;
        }
    }

    cout << result;


}
