#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

pair<int,int> p[100000];
queue<pair<int,int>> q;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,d;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
        if(p[i].first > p[i].second) swap(p[i].first,p[i].second);
    }

    cin >> d;

    sort(p,p+n,cmp);


    int s,result = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i=0;i<n;i++){
        s = p[i].second - d;
        pq.push(p[i]);
        while (!pq.empty() && pq.top().first < s){
            pq.pop();
        }

        result = max(result,(int)pq.size());
    }

    cout << result;
}
