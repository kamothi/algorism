#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<pair<int,int>> v[50001];
int dist[50001];

// 다익스트라
// 최소한의 소들을 지나가야함
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    priority_queue<pair<int,int>> pq;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }

    for (int i = 1; i <= n; i++) dist[i] = 1e9;

    pq.push({0,1});

    dist[1] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int newcost = v[cur][i].second + cost;
            if (dist[next] > newcost) {
                dist[next] = newcost;
                pq.push({ -dist[next],next });
            }
        }
    }

    cout << dist[n];
}
