#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> v[10001];
stack<int> s;
int d[10001];
int id;
vector<vector<int>> SCC;
bool finished[10001];
int sccNum;
int sn[10001];

bool compare(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int dfs(int n){
    d[n] = ++id;
    s.push(n);

    int result = d[n];

    for (int next : v[n]) {
        if (d[next] == 0) result = min(result, dfs(next));
        else if (!finished[next]) result = min(result, d[next]);
    }

    if (result == d[n]) {
        vector<int> scc;
        while (1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            sn[t] = sccNum;
            if (t == n) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
        sccNum++;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) dfs(i);
    }

    cout << sccNum << "\n";
    sort(SCC.begin(), SCC.end(), compare);

    for(int i=0;i<sccNum;i++){
        for(int j=0;j<SCC[i].size();j++){
            cout << SCC[i][j] << " ";
        }
        cout << "-1" << "\n";
    }
}
