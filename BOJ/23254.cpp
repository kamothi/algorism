#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return min(100-a.first,a.second) < min(100-b.first,b.second);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m,result=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

    cin >> n >> m;
    n = n*24;
    vector<pair<int,int>> input(m);
    for(int i=0;i<m;i++){
        cin >> input[i].first;
    }
    for(int i=0;i<m;i++){
        cin >> input[i].second;
    }
    for(int i=0;i<m;i++){
        pq.push({input[i].first,input[i].second});
    }
    while(n--){
        if(pq.empty()) break;
        pair<int,int> tmp = pq.top();
        pq.pop();
        tmp.first += tmp.second;
        if(tmp.first > 100){
            result += 100;
            continue;
        }
        pq.push(tmp);

    }
    while(!pq.empty()){
        pair<int,int> tmp = pq.top();
        pq.pop();
        if(tmp.first > 100){
            result += 100;
        }
        else{
            result += tmp.first;
        }
    }
    cout << result;
}
