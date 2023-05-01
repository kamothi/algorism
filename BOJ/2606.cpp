#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
int cnt;
vector<int> node[101];
bool visited[101];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : node[now]){
            if(!visited[next]){
                q.push(next);
                cnt++;
                visited[next] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        node[tmp1].push_back(tmp2);
        node[tmp2].push_back(tmp1);
    }
    bfs(1);
    cout << cnt;
}
