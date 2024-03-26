#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

vector<pair<int,int>> v[100001];
int n;
int energy[100001];
bool visited[100001];
pair<ll, ll> table[18][100001];

void dfs(int now){
    visited[now] = true;

    for (auto& next : v[now])
    {
        if (visited[next.first]) continue;
        table[0][next.first] = { now,next.second };
        dfs(next.first);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for(int i=1;i<=n;i++) cin >> energy[i];

    for(int i=0;i<n-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({ a, c });
    }

    dfs(1);
    table[0][1].first = 1;

    for (int i = 1; i < 17; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j].first = table[i-1][table[i-1][j].first].first;
            table[i][j].second = table[i - 1][table[i - 1][j].first].second + table[i - 1][j].second;
        }
    }

    int target;
    for(int i = 1;i <= n; i++) {
        target = i;
        for (int j = 17; j >= 0; j--) {
            if (table[j][target].second == 0 || table[j][target].second > energy[i]) continue;
            energy[i] -= table[j][target].second;
            target = table[j][target].first;
        }
        cout << target << "\n";
    }

}
