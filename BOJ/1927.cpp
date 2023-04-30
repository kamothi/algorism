#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int,vector<int>,greater<>> pq;
    int n;
    cin >> n;
    while(n--){
        int tmp;
        cin >> tmp;
        if(tmp == 0) {
            if(pq.empty()){
                cout << 0 <<"\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
            continue;
        }
        pq.push(tmp);
    }
}
