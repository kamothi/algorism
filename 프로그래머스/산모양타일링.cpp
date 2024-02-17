#include <string>
#include <vector>

using namespace std;

int dp1[100000]; // 있는 경우
int dp2[100000]; // 없는 경우

int solution(int n, vector<int> tops) {
    int answer = 0;
    // n과 n-1 사이에 겹치는 부분이 존재
    
    if(tops[0] == 1){
        dp1[0] = 1;
        dp2[0] = 3;
    }
    else{
        dp1[0] = 1;
        dp2[0] = 2;
    }
    
    for(int i=1;i<n;i++){
        if(tops[i] == 1){
            dp1[i] = (dp1[i-1] + dp2[i-1]) % 10007;
            dp2[i] = (dp1[i-1]*2 + dp2[i-1]*3)% 10007;
        }
        else {
            dp1[i] = (dp1[i-1] + dp2[i-1]) % 10007;
            dp2[i] = (dp1[i-1] + dp2[i-1]*2) % 10007;
        }
    }
    return (dp1[n-1] + dp2[n-1]) % 10007;
    
}
