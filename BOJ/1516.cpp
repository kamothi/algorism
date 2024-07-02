#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int t[501];
int inDegree[501];
vector<int> edge[501];
int result[501];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;

    queue<int> q;
    for(int i=1;i<=n;i++){
        cin >> t[i];

        while(1){
            int a;
            cin >> a;
            if(a == -1) break;
            edge[a].push_back(i);
            inDegree[i]++;
        }
    }

    for(int i=1;i<=n;i++) {
        if(inDegree[i] == 0) {
            q.push(i);
            result[i] = t[i];
        }
    }

    while(!q.empty()){
        int ft = q.front();
        q.pop();
        for(int i=0;i<edge[ft].size();i++){
            int next = edge[ft][i];
            inDegree[next]--;
            result[next] = max(result[next],result[ft] + t[next]);
            if(inDegree[next] == 0) q.push(next);
        }
    }

    for(int i=1;i<=n;i++) cout << result[i] << "\n";

}
