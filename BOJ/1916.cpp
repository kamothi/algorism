#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int INF = 0x4f4f4f4f;
int n,m; //노드와 간선의 개수
int s,e;
vector<pair<int,int>> v[1001];
int d[1001];

int findMinCity(int start){
    priority_queue<pair<int,int>> pq;
    d[start] = 0;
    pq.push(make_pair(start,0));
    while(!pq.empty()){
        int current = pq.top().first;
        int di = -pq.top().second;
        pq.pop();
        if(d[current] < di) continue;
        for(int i=0;i<v[current].size();i++){
            int next = v[current][i].first;
            int nextDistance = v[current][i].second + di;
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }

        }
    }
    return d[e];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<1001;i++) d[i] = INF;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int node1,node2,dis;
        cin >> node1 >> node2 >> dis;
        v[node1].push_back(make_pair(node2,dis));
    }
    cin >> s >> e;
    cout << findMinCity(s);
}
