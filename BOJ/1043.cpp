#include<iostream>
#include<vector>

using namespace std;
int node[51];

void make_set(int n){
    for(int i = 1; i <= n; i++) node[i] = i;
}

int Find(int x) {
    if(x==node[x]) return x;
    return node[x] = Find(node[x]);
}

void Union(int a, int b) {
    node[Find(a)] = Find(b);
}

vector<int> v2[51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> v(51);
    make_set(n);
    int result = 0;

    int liar;
    cin >> liar;
    for(int i=0;i<liar;i++){
        cin >> v[i];
    }

    for(int i=0;i<m;i++){
        int cnt;
        cin >> cnt;
        for(int j=0;j<cnt;j++){
            int tmp;
            cin >> tmp;
            v2[i].push_back(tmp);
            if(j>0) Union(node[v2[i][j]],node[v2[i][j-1]]);
        }
    }

    for(int i=0;i<m;i++){
        bool flag = false;
        for(int j=0;j<v2[i].size();j++){
            for(int k=0;k<liar;k++){
                if(Find(node[v[k]]) == Find(node[v2[i][j]])) {
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) result++;
    }

    cout << result;
}
