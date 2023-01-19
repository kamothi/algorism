#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> P;
priority_queue<int, vector<int>,greater<int>> q;
bool com(P a, P b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    P meeting[100000];
    int n;
    int cnt=1;
    int MAX=0;
    int check=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        meeting[i] = make_pair(a,b);
    }
    sort(meeting,meeting+n,com);
    q.push(meeting[0].second);
    for(int i=1;i<n;i++){
       while(!q.empty() && q.top() <= meeting[i].first) q.pop();
       q.push(meeting[i].second);
       MAX = max((int)q.size(),MAX);
    }
    cout << MAX;
}
