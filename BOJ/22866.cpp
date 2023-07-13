#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
pair<int,pair<int,int>> v[100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int,int>> left;
    stack<pair<int,int>> right;
    int n;
    cin >> n;
     // 크기, 개수, 위치
    for(int i=0;i<n;i++) cin >> v[i].first;
    for(int i=0;i<n;i++){
        while(1){
            if(left.empty()){
                left.push({v[i].first,i+1});
                v[i].second.first = 0;
                v[i].second.second = 200000;
                break;
            }
            pair<int,int> tmp = left.top();
            if(tmp.first > v[i].first){
                v[i].second.first = left.size();
                v[i].second.second = tmp.second;
                left.push({v[i].first,i+1});
                break;
            }
            else left.pop();

        }
    }
    for(int i=n-1;i>=0;i--){
        while(1){
            if(right.empty()){
                right.push({v[i].first,i+1});
                break;
            }
            pair<int,int> tmp = right.top();
            if(tmp.first > v[i].first){
                v[i].second.first += right.size();
                if(abs(i+1-tmp.second) < abs(i+1-v[i].second.second)){
                    v[i].second.second = tmp.second;
                }
                right.push({v[i].first,i+1});
                break;
            }
            else right.pop();
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i].second.first <<" ";
        if(v[i].second.first == 0) {
            cout << "\n";
            continue;
        }
        else cout << v[i].second.second << "\n";
    }
}
