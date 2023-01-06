#include<iostream>

using namespace std;

int n,l,r,x,cnt=0;
int arr[15];

void getAnswer(int id, int Min, int Max, int sum){
    if(id == n){
        if(sum < l || sum > r) return;
        if((Max-Min) < x) return;
        cnt++;
        return;
    }
    getAnswer(id+1,Min,Max,sum);
    getAnswer(id+1,min(Min,arr[id]),max(Max,arr[id]),sum+arr[id]);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> l >> r >> x;
    for(int i=0;i<n;i++) cin >> arr[i];
    getAnswer(0,10000000,0,0);
    cout << cnt;
}
