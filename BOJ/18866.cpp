#include<iostream>
#include<algorithm>

using namespace std;

// 첫 번째가 행복도, 두 번째가 피로도
pair<int,int> day[1000001];
pair<int,int> y[1000001];
pair<int,int> o[1000001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = -1;

    int Max1 = -1,Max2 = -1,Min1 = 100000000,Min2 = 10000000;
    cin >> n;

    for(int i=1;i<=n;i++) cin >> day[i].first >> day[i].second;

    for(int i=1;i<=n;i++){
        // 최소 행복
        if(day[i].first != 0 && day[i].first < Min1) Min1 = day[i].first;
        // 최대 피로
        if(day[i].second != 0 && day[i].second > Max2) Max2 = day[i].second;
        y[i].first = Min1;
        y[i].second = Max2;
    }
    for(int i=n;i>=0;i--){
        // 최대 행복
        if(day[i].first != 0 && day[i].first > Max1) Max1 = day[i].first;
        // 최소 피로
        if(day[i].second != 0 && day[i].second < Min2) Min2 = day[i].second;
        o[i].first = Max1;
        o[i].second = Min2;
    }
    for(int i=n-1;i>=0;i--){
        if(y[i].first > o[i+1].first && y[i].second < o[i+1].second) {
            result = max(i,result);
        }
    }

    cout << result;
}
