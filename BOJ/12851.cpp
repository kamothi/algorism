#include<iostream>
#include<queue>

using namespace std;

bool visit[200001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    int result1=0,result2=0;
    cin >> n >> k;

    queue<pair<int,int>> q;
    q.push({n,0});
    visit[n] = 1;
    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        visit[now] = 1;

        if (result1 && result1 == time && now == k) result2++;
        if(!result1 && now == k){
            result2++;
            result1 = time;
        }
        if(now-1 >= 0 && !visit[now-1]) q.push({now-1,time+1});
        if(now+1 < 100001 && !visit[now+1]) q.push({now+1,time+1});
        if(now*2 < 200001 && !visit[now*2]) q.push({now*2,time+1});
    }
    cout << result1 << "\n" << result2;


}
