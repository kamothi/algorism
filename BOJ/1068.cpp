#include<iostream>
#include<vector>

using namespace std;

int n, delN,root;
vector<int> node[51];
int visited[51];
int result = 0;

void dfs(int x){
    if(visited[x]) return;
    visited[x] = 1;
    bool isLeaf = true;
    for (int i = 0; i < node[x].size(); i++) {
		int next = node[x][i];
		if (!visited[next]) {
			dfs(next);
			isLeaf = false; 
		}
	}
    if (isLeaf) result++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   cin >> n;
   for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(a==-1) root = i;
        else node[a].push_back(i);
   }

    cin >> delN;
	visited[delN] = true;
	dfs(root);
	cout << result << "\n";
    return 0;
}
