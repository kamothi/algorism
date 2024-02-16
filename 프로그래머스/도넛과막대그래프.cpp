#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int in[1000001];
int out[1000001];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int end = 0;
    int result1=0,result2=0,result3=0,result4=0;
    for(int i=0;i<edges.size();i++){
        in[edges[i][1]]++;
        out[edges[i][0]]++;
        end = max({end,edges[i][1],edges[i][0]});
    }
    
    for(int i=1;i<=end;i++){
        if(out[i] == 0) result3++;
        if(out[i] == 2 && in[i] >= 2) result4++;
        if(out[i] >= 2 && in[i] == 0) result1 = i;
    }
    
    result2 = out[result1] - (result3 + result4);
    
    answer.push_back(result1);
    answer.push_back(result2);
    answer.push_back(result3);
    answer.push_back(result4);
    return answer;
}
