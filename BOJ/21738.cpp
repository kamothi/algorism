#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, s, p; //block 개수 n, 지지대, 펭귄 위치
vector<int> dist(328000,-1);
vector<int> block[328001];
void dfs(int position){
    for(int u : block[position]){
        if (dist[u] == -1) {
            dist[u] = dist[position] + 1;
            dfs(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tmp1,tmp2;

    cin >> n >> s >>p;

    for(int i=0;i<n-1;i++){
        cin >> tmp1 >> tmp2;
        block[tmp1].push_back(tmp2);
        block[tmp2].push_back(tmp1);
    }
    dist[p]=0;
    dfs(p);
    sort(dist.begin()+1,dist.begin()+s+1);
    cout << n-1-(dist[1] + dist[2]);

}
