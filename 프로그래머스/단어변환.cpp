#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[50];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> q;
    q.push({begin,0});
    while(!q.empty()){
        string nowS = q.front().first;
        int nowCnt = q.front().second;
        q.pop();
        if(nowS == target){
            answer = nowCnt;
            break;
        }
        for(int i=0;i<words.size();i++){
            int cnt = 0;
            if(!visited[i]){
                for(int j=0;j<words[i].size();j++){
                    if(nowS[j] != words[i][j]) cnt++;
                }
                if(cnt == 1){
                    visited[i] = true;
                    q.push({words[i],nowCnt+1});
                }
            }
        }
    }
    
    return answer;
}
