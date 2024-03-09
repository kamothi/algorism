#include<iostream>
#include<algorithm>

using namespace std;

int n;
pair<int,int> eggs[8];
int result = 0;

void solve(int idx){
    if(idx > n) return;

    for(int i=0;i<n;i++){
        if(eggs[idx].first <= 0) solve(idx+1);
        else if(i==idx || eggs[i].first <= 0) continue;
        else {
            eggs[i].first -= eggs[idx].second;
            eggs[idx].first -= eggs[i].second;
            solve(idx+1);
            eggs[i].first += eggs[idx].second;
            eggs[idx].first += eggs[i].second;
        }
    }

    int tmp = 0;
    for(int i=0;i<n;i++) if(eggs[i].first <= 0)  tmp++;
    result = max(result,tmp);
    return;
}

int main(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> eggs[i].first >> eggs[i].second;
    solve(0);

    cout << result;

}
