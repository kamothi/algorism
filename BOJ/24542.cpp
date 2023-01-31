#include<iostream>
#include<vector>

using namespace std;

int n,m;
long long cnt =1;
long long result=1;
vector<int> v[200001];
bool visited[200001];

long long dfs(int next_num){
    for(int next : v[next_num]) {
        if(visited[next]) continue;
        visited[next] = 1;
        cnt ++;
        dfs(next);
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(visited,200001,false);
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        visited[i] = 1;
        cnt =1;
        result = (result*dfs(i))%1000000007;
    }
    cout << result;
}
