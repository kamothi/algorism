//
// Created by 김광일 on 2022/11/29.
//
#include<iostream>
#include<algorithm>
int N;
int dp[1000001];
using namespace std;

int main(){
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] =2;
    dp[7] =1;
    for(int i=8;i<=N;i++){
        dp[i] = min({dp[i-1],dp[i-2],dp[i-5],dp[i-7]})+1;
    }
    cout << dp[N];
}
