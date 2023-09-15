#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; // 도시의 개수, 도로의 개수
    bool city[2001] ={0,};
    vector<int> bomb;

    int t;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<int> result;
    bool bomb_city[2001] = {false,};
    for(int i=0;i<m;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    cin >> t;
    vector<int> destroy(t);
    for(int i=0;i<t;i++) {
        cin >> destroy[i];
        city[destroy[i]] = true;
    }

    for(int i=0;i<t;i++){
        queue<int> q;
        int tmp;
        q.push(destroy[i]);
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            vector<int> tp;
            bool check = false;
            for (int j = 0; j < v[tmp].size(); j++) {
                if(city[v[tmp][j]] == false) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                result.push_back(tmp);
                bomb_city[tmp] = true;
                for (int j = 0; j < v[tmp].size(); j++) {
                    bomb_city[v[tmp][j]] = true;
                }
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        if (bomb_city[i] != city[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << result.size() << "\n";
    for(int i=0;i<result.size();i++) cout << result[i] << " ";



}
