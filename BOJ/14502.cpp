#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;


int n, m; // 3 <= n,m <= 8
int arr[9][9] = { 0, };
int cnt = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[9][9];

int bfs(pair<int,int> a, pair<int, int>  b, pair<int, int>  c) {
    int temp[9][9];
    int tcnt = cnt-3;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp[i][j] = arr[i][j];
            if (arr[i][j] == 2) q.push(make_pair(i, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
           visited[i][j] = false;
        }
    }
    temp[a.first][a.second] = 1;
    temp[b.first][b.second] = 1;
    temp[c.first][c.second] = 1;

    while (!q.empty()) {
        pair<int, int> p;
        p.first = q.front().first;
        p.second = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextx = p.first + dx[i];
            int nexty = p.second + dy[i];
            if (nextx < 1 || nexty > m || nextx > n || nexty < 1) continue;
            if (!visited[nextx][nexty] && temp[nextx][nexty] == 0) {
                temp[nextx][nexty] = 2;
                q.push(make_pair(nextx, nexty));
                visited[nextx][nexty] = true;
                tcnt--;
            }
        }

    }
    return tcnt;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> qq;
    int result=-1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                cnt++;
                qq.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < qq.size(); i++) {
        for (int j = i + 1; j < qq.size(); j++) {
            for (int l = j + 1; l < qq.size(); l++) {
                int tmp = bfs(qq[i], qq[j], qq[l]);
               // cout << tmp << "\n";
                result = max(result, tmp);
            }
        }
    }
    cout << result;
}
