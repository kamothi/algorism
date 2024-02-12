#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long dp[sequence.size()][2];
    
    dp[0][0] = (long long)sequence[0]; // 홀수번째 -1
    dp[0][1] = (long long)-1*sequence[0]; // 짝수번째 -1;
    answer = max(dp[0][0],dp[0][1]);
    for(int i=1;i<sequence.size();i++){
        dp[i][0] = max((long long) sequence[i],dp[i-1][1] + (long long) sequence[i]);
        dp[i][1] = max((long long) -1*sequence[i],dp[i-1][0] - (long long) sequence[i]);
        answer = max(answer,dp[i][0]);
        answer = max(answer,dp[i][1]);
        
    }
    return answer;
}
