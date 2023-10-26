#include<iostream>
#include<vector>

using namespace std;

vector<vector<pair<int,int>>> v1(100001);
bool visited[100001];
int result = -1;
int target;
void dfs(int vertex, int sum){
    if(visited[vertex]) return;
    visited[vertex] = true;

    if(result < sum){
        result = sum;
        target = vertex;
    }

    for(int i=0;i<v1[vertex].size();i++){
        int n = v1[vertex][i].first;
        int value = v1[vertex][i].second;
        if(!visited[n]) dfs(n,sum+value);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v; // 정점의 개수
    cin >> v;
    for(int i=1;i<=v;i++){
        int tmp1,tmp2,ver;
        cin >> ver;
        while(1){
            cin >> tmp1;
            if(tmp1 == -1) {
                break;
            }
            cin >> tmp2;
            v1[tmp1].push_back({ver,tmp2});
            v1[ver].push_back({tmp1,tmp2});
        }
    }

    dfs(1,0);
    for(int i=1;i<=v;i++) visited[i] = false;
    dfs(target,0);
    cout << result;
}
