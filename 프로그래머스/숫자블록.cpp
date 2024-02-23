#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(int i=begin;i<=end;i++){
        if(i == 1) {
            answer.push_back(0);
            continue;
        }
        int cnt = 0;
        int tmp = 0;
        for(int j=2;j*j<=i;j++){
            if (i % j == 0) {
                if(i/j > 10000000) tmp=max(tmp,j);
                else tmp = max(tmp,i/j);
                cnt++;
            }
        }
        if(!cnt) answer.push_back(1);
        else answer.push_back(tmp);
    }
    return answer;
}
