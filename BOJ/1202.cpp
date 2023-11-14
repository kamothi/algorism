#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

pair<int,int> stone[300000];
int w[300000];
priority_queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    long long result = 0;
    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> stone[i].first >> stone[i].second;
    }
    for(int i=0;i<k;i++) cin >> w[i];

    sort(stone,stone+n);
    sort(w,w+k);
    int pos=0;
    for(int i=0;i<k;i++){
        while(pos<n&&stone[pos].first <= w[i]){
            q.push(stone[pos++].second);
        }
        if(!q.empty()){
            result += q.top();
            q.pop();
        }
    }

    cout << result;

}
