#include <string>
#include <vector>
#include <queue>

using namespace std;

void init(bool visited[100001]){
    for(int i=0;i<100001;i++) visited[i] = false;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    bool visited[100000];
    
    vector<vector<int>> node(n+1);
    for(int i=0;i<roads.size();i++) {
        node[roads[i][0]].push_back(roads[i][1]);
        node[roads[i][1]].push_back(roads[i][0]);
    }
    
    for(int i=0;i<sources.size();i++){
        if(destination == sources[i]) {
            answer.push_back(0);
            continue;
        }
        queue<pair<int,int>> q;
        init(visited);
        int result = 0;
        q.push({sources[i],0});
        visited[sources[i]] = true;
        while(!q.empty()){
            int now = q.front().first;
            int time = q.front().second;
            if(now == destination){
                result = time;
                break;
            }
            q.pop();
            for(int i=0;i<node[now].size();i++){
                if(!visited[node[now][i]]){
                    visited[node[now][i]] = true;
                    q.push({node[now][i],time+1});
                }
            }
        }
        if(result) answer.push_back(result);
        else answer.push_back(-1);
    }
    
    return answer;
}
