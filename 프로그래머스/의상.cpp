#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 각 종류별로 최대 1가지
// 종류 중에 하나만 다르더라도 다른 의상
// 옷의 조합의 수a
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> c;
    
    for(auto& cloth : clothes){
        string type = cloth[1];
        c[type]++;
    }
    
    for(auto& johap : c){
        answer *= (johap.second+1);
    }
    return answer-1;
}
