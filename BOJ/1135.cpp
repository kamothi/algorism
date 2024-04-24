#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v[50];
bool visited[50];

int dfs(int now){

    vector<int> child;
    int ans = 0;
    int tmp = v[now].size();
    for(int i=0;i<v[now].size();i++){
        child.push_back(dfs(v[now][i]));
    }

    sort(child.begin(),child.end(),greater<>());

    for(int i=0;i<tmp;i++){
        ans = max(ans,child[i]+i+1);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int empty;
    cin >> n;
    cin >> empty;
    for(int i=1;i<n;i++) {
        int t;
        cin >> t;
        v[t].push_back(i);
    }


    cout << dfs(0);
}
