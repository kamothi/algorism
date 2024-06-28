#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;


ll d[10001];
ll d2[10001];
vector<pair<int,ll>> edge[10001];
vector<pair<int,ll>> inverseEdge[10001];

// 다익스트라
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,m,x;
    ll result = -1;
    cin >> n >> m >> x;

    // 해당 위치까지의 값과 위치
    priority_queue<pair<ll,int>> pq;
    for(int j=1;j<=n;j++) {
        d[j] = 1e18;
        d2[j] = 1e18;
    }

    for(int j=0;j<m;j++){
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        inverseEdge[b].push_back({a,c});
    }

    pq.push({0,x});
    while(!pq.empty()){
        pair<ll,int> p = pq.top();
        pq.pop();
        p.first = -p.first;

        if(p.first > d[p.second]) continue;

        for(auto& next : edge[p.second]){
            if(p.first + next.second < d[next.first]){
                d[next.first] = p.first + next.second;
                pq.push({-d[next.first],next.first});
            }
        }
    }

    // 반대 방향 체크
    pq.push({0,x});
    while(!pq.empty()){
        pair<ll,int> p = pq.top();
        pq.pop();
        p.first = -p.first;

        if(p.first > d2[p.second]) continue;

        for(auto& next : inverseEdge[p.second]){
            if(p.first + next.second < d2[next.first]){
                d2[next.first] = p.first + next.second;
                pq.push({-d2[next.first],next.first});
            }
        }
    }

    for(int j=1;j<=n;j++) {
        if(j == x) continue;
        result = max(d[j]+d2[j],result);
    }

    cout << result;



}
