#include<iostream>
#include<stack>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll result = 0;
    stack<pair<int,int>> s;
    cin >> n;
    int height[500000];
    for(int i=0;i<n;i++) cin >> height[i];
    vector<ll> cnt(500000,1);

    int now = 0;
    while(now < n){
        if(s.size() == 0){
            s.push({height[now],cnt[now]});
            now++;
        }
        else {
            if(s.top().first > height[now]){
                result += 1;
                s.push({height[now],cnt[now]});
                now++;
            }
            else if(s.top().first == height[now]){
                cnt[now] += s.top().second;
                result += s.top().second;
                s.pop();
            }
            else{
                result += s.top().second;
                s.pop();
            }
        }
    }

    cout << result;
}
