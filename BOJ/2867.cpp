#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// 스택으로 최대값, 최소값 관리. 즉 i번까지의 최대 최소를 관리해서 가자
struct node{
    long long val;
    long long idx;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    long long result = 0;
    cin >> n;
    vector<long long> vn(n+1),vx(n+1);

    stack<node> MAX,MIN;
    MAX.push({(long long)1e9+1,0});
    MIN.push({0,0});


    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        while(MIN.top().val>x) MIN.pop();
        while(MAX.top().val<x) MAX.pop();

        vn[i]=vn[MIN.top().idx]+(i-MIN.top().idx)*x;
        vx[i]=vx[MAX.top().idx]+(i-MAX.top().idx)*x;
        result+=vx[i]-vn[i];
        MIN.push({x,i}); MAX.push({x,i});
    }
    cout << result;

}
