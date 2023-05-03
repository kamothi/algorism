#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v[100001];
long long dp[100001][2]; //0이 흰색, 1이 검은색
pair<int,int> cost[100001];
long long result1 = 0;
long long result2 = 0;

long long findMinValue(int now,bool check){//check가 0이면 white
    if(dp[now][check] == 0){
        check == 0 ? dp[now][check] += cost[now].first : dp[now][check] += cost[now].second;
    }
    else return dp[now][check];
    for(int next : v[now]){
        if(!check){ // 자신이 화이트
            dp[now][0] += min(findMinValue(next,0), findMinValue(next,1));
        }
        else{ // 자신이 블랙
            dp[now][1] += findMinValue(next,0);
        }
    }
    if(!check)  return dp[now][0];
    return dp[now][1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
    }
    for(int i=0;i<n;i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cost[i] = make_pair(tmp1,tmp2);
    }
    result1 = findMinValue(0,0);
    result2 = findMinValue(0,1);

    cout << min(result1,result2);

}
