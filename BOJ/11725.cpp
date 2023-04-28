#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> v[100001];
bool visited[100001];
int parentNum[100001];

void findParent(int x){
    if(visited[x]) return;
    visited[x]=true;
    for(int next : v[x]){
        if(parentNum[next] == 0) {
            parentNum[next] = x;
            findParent(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n-1;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    findParent(1);
    for(int i=2;i<=n;i++){
        cout << parentNum[i] << "\n";
    }
}
