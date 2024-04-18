#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector<pair<int,int>> tree[1001];
bool visited[1001];

void init(){
    for(int i=0;i<=1001;i++) visited[i] = false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    while(m--){
        int a,b;
        int result = 0;
        cin >> a >> b;
        queue<pair<int,int>> q;

        q.push({a,0});
        init();
        while(!q.empty()){
            visited[q.front().first] = true;
            int now = q.front().first;
            int tmp = q.front().second;
            if(now == b){
                cout << tmp << "\n";
                break;
            }
            q.pop();

            for(int i=0;i<tree[now].size();i++){
                if(!visited[tree[now][i].first]){
                    q.push({tree[now][i].first,tree[now][i].second + tmp});
                }
            }
        }
    }
}
