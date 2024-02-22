#include <string>
#include <vector>

using namespace std;

// 문자열 길이가 26 그렇기에 n^2도 충분히 가능 max = 26*20*26 <= 10^6
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0;i<skill_trees.size();i++){
        bool check[26] = {0,};
        bool isTrue = true;
        for(int j=0;j<skill_trees[i].size();j++){
            for(int k=0;k<skill.size();k++){
                if(skill_trees[i][j] == skill[k]){
                    if(k==0 || check[k-1]) check[k] = true;
                    else {
                        isTrue = false;
                        break;
                    }
                }
            }
            if(!isTrue) break;
        }
        if(isTrue) answer++;
    }
    if(answer) return answer;
}
