#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;
vector<int> v[2001];
int visited[2001];
bool answer = true;

void dfs(int curr){
    for(int next:v[curr]){
        if(visited[next] == -1){
           if (visited[curr] == 1) visited[next] = 0;
           else visited[next] = 1;
           dfs(next);
        }
        else if(visited[next] == visited[curr]) answer = false;
    }
}

int main(){
    int n,m;
    for(int i=0;i<2001;i++) {
            visited[i] = -1;
    }
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    for (int i=1; i<=n; i++) {
        if (visited[i] == -1) {
            visited[i] = 1;
            dfs(i);
        }
    }
    cout << answer << '\n';
}
