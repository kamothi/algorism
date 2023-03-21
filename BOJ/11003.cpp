#include<iostream>
#include<queue>

using namespace std;

struct compare{
    bool operator()(pair<int, int>a, pair<int, int>b){
        return a.first>b.first;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    int n,l;
    cin >> n >> l;

    for(int i=0;i<n;i++){
        int MIN = i-l+1;
        int num;
        cin >> num;
        pq.push(make_pair(num,i));
        while(1){
            if(pq.top().second >= MIN) break;
            pq.pop();
        }
        cout << pq.top().first <<" ";
    }

}
