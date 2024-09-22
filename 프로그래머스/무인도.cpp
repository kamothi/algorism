#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
int check[8];

void dfs(int k, int cnt, vector<vector<int>> &dungeons) {
    answer = max(answer, cnt);
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (check[i] == 0 && k >= dungeons[i][0]) {
            check[i] = 1;
            dfs(k - dungeons[i][1], cnt + 1, dungeons);
            check[i] = 0;
        }
    }
}

// 던전 탐험 시작 - 최소 필요 피로도(현재 던전을 탐험하기 위해 최소 조건)
// 던전 종료 - 소모 피로도(던전 종료 후 소모)
// 현재 피로도 k, dungeons(최소 필요 피로도, 소모 피로도)
// 탐험 가능한 최대 던전수
int solution(int k, vector<vector<int>> dungeons) {
    dfs(k,0,dungeons);
    
    return answer;
}
