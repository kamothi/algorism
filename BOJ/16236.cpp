#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n;
int map[20][20];
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int totalTime = 0;
vector<pair<int,pair<int,int>>> v;

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if (a.first <= b.first)
    {
        if (a.first == b.first)
        {
            if (a.second.first <=b.second.first)
            {
                if (a.second.first == b.second.first)
                {
                    if (a.second.second < b.second.second)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool check(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n) return false;
    return true;
}

void bfs(int x, int y, bool visited[20][20],int sharkSize){
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{x,y}});
    visited[x][y] = true;
    while(!q.empty()){
        int xx = q.front().second.first;
        int yy = q.front().second.second;
        int Time = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nextX = xx+dx[i];
            int nextY = yy + dy[i];
            if(check(nextX,nextY) && !visited[nextX][nextY]){
                if(map[nextX][nextY] <= sharkSize){
                    if(map[nextX][nextY] > 0 && map[nextX][nextY] < sharkSize){
                        v.push_back({Time+1,{nextX,nextY}});
                        visited[nextX][nextY] = true;
                        q.push({Time+1,{nextX,nextY}});
                    }
                    else{
                        visited[nextX][nextY] = true;
                        q.push({Time+1,{nextX,nextY}});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    pair<int,pair<int,int>> shark;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 9) {
                shark = {2,{i,j}};
                map[i][j] = 0;
            };

        }
    }
    int Eat = 0;
    while(1){
        v.clear();
        bool visit[20][20] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) visit[i][j] = 0;
        }
        bfs(shark.second.first,shark.second.second,visit,shark.first);
        if(v.size() == 0){
            cout << totalTime;
            break;
        }
        else if(v.size() == 1){
            shark.second.first = v[0].second.first;
            shark.second.second = v[0].second.second;
            Eat++;
            map[v[0].second.first][v[0].second.second] = 0;
            if(Eat >= shark.first){
                Eat -= shark.first;
                shark.first++;
            }
            totalTime += v[0].first;
        }
        else{
            sort(v.begin(),v.end(),cmp);
            shark.second.first = v[0].second.first;
            shark.second.second = v[0].second.second;
            Eat++;
            map[v[0].second.first][v[0].second.second] = 0;
            if(Eat >= shark.first){
                Eat -= shark.first;
                shark.first++;
            }
            totalTime += v[0].first;
        }

    }

}
