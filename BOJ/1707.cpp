#include<iostream>
#include<vector>
using namespace std;

int v[20001];
vector<vector<int>> g(20001);

bool dfs(int cur, int color){
    bool ret = true;
    v[cur] =color;
    int nxt_color = (color == 1) ? 2: 1;
    for(int nxt : g[cur]){
        if (v[nxt] == color) return false;
        if (v[nxt]) continue;
        ret &= dfs(nxt, nxt_color);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int vertex,edge;
        bool ret = true;
        cin >> vertex >> edge;
        for(int i=0;i<edge;i++){
            int tmp1,tmp2;
            cin >> tmp1 >> tmp2;
            g[tmp1].push_back(tmp2);
            g[tmp2].push_back(tmp1);
        }

        for(int i=1;i<=vertex;i++){
            if(!v[i]){
                ret &= dfs(i,1);
            }
        }

        if(ret) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        for(int i=1;i<=vertex;i++){
            v[i] = 0;
            g[i].clear();
        }
    }

}
