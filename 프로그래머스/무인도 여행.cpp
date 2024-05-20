#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int s1,s2;


bool check(int x, int y){
    return (x >= 0 && x < s1 && y >= 0 && y < s2);
}

bool visited[100][100];

void dfs(int x, int y, int& tmp,vector<string>& maps){
    visited[x][y] = true;
    tmp += maps[x][y] - '0';
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(check(nx,ny) && !visited[nx][ny] && maps[nx][ny] != 'X') dfs(nx,ny,tmp,maps);
    }
}

// 바다는 X, 숫자는 식량 
// 상, 하, 좌, 우로 적힌 숫자들의 합 = 체류 기간
// 각 섬에 대해서 최대로 머물 수 있는 기간 오름차순으로
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    s1 = maps.size();
    s2 = maps[0].size();
    int cnt = 0;
    int tmp;
    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            tmp = 0;
            if(!visited[i][j] && maps[i][j] != 'X') {
                dfs(i,j,tmp,maps);
            }
            if(tmp != 0){
                cnt++;
                answer.push_back(tmp);
            }
            
        }
    }
    
    if(!cnt) {
        answer.push_back(-1);
    }
    else sort(answer.begin(), answer.end());
    
    return answer;
}
