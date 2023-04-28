#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

bool visited[10001];
int Max,diameter=-1,End;
vector<pair<int,int>> v[10001];

void findMaxNode(int x,int len){
    if(visited[x]) return;
    if(diameter < len){
        End = x;
        diameter = len;
    }
    visited[x] = true;
    for(int i=0;i<v[x].size();i++){
        findMaxNode(v[x][i].first,v[x][i].second + len);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n-1;i++){
        int tmp1,tmp2,tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        v[tmp1].push_back(make_pair(tmp2,tmp3));
        v[tmp2].push_back(make_pair(tmp1,tmp3));
    }

    findMaxNode(1,0);
    for(int i=0;i<=n;i++) visited[i] = false;
    diameter = 0;
    findMaxNode(End,0);
    cout << diameter;
}
