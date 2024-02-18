#include <string>
#include <vector>

using namespace std;

int n;
bool visited[11];
vector<vector<int>> cases1;

// a가 선택할 주사위 경우의 수
void solve(int idx,vector<int>& tmp){
    // 절반은 a 절반은 b 방문되어 있는 놈이 a꺼라고 가정
    if(tmp.size() == n/2){
        cases1.push_back(tmp);
        return;
    }
    
    for(int i=idx;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            tmp.push_back(i);
            solve(i+1,tmp);     
            visited[i] = false;
            tmp.pop_back();   
        }
    }
}

void Sum(int idx,vector<vector<int>>& dice,int& sum,vector<int>& cases,vector<int>& result){
    if(idx == cases.size()){
        result.push_back(sum);
        return;
    }
    
    for(int i=0;i<dice[cases[idx]].size();i++){
        sum += dice[cases[idx]][i];
        Sum(idx+1,dice,sum,cases,result);
        sum -= dice[cases[idx]][i];
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer(dice.size()/2);
    vector<int> tmp;
    n= dice.size();
    
    solve(0,tmp);
    int win = -1;
    int cases1_size = cases1.size();
    for(int i=0;i<cases1_size;i++){
        vector<int> sumA;
        vector<int> sumB;
        int sumTmpA = 0;
        int sumTmpB = 0;
        Sum(0,dice,sumTmpA,cases1[i],sumA);
        Sum(0,dice,sumTmpB,cases1[cases1_size-i-1],sumB);
        
        int tmp = 0;
        for(int j=0;j<sumA.size();j++){
            for(int k=0;k<sumB.size();k++){
                if(sumA[j] > sumB[k]) tmp++;
            }
        }

        if(tmp > win) {
            win = tmp;
            for(int j=0;j<cases1[i].size();j++) answer[j] = cases1[i][j]+1;
        }
    }
    return answer;
}
