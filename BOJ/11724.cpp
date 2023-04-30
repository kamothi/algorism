#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<int> node[1001];
bool visited[1001];
int n,m;

void bfs(int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int tmp : node[t]){
            if(!visited[tmp]){
                q.push(tmp);
                visited[tmp] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int t1,t2;
        cin >> t1 >> t2;
        node[t1].push_back(t2);
        node[t2].push_back(t1);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(i);
            sum++;
        }
    }
    cout <<sum;
}
