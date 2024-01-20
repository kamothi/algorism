#include<iostream>

using namespace std;

int n;
long long dp[31][61];

void init(){
    for(int i=0;i<31;i++) 
        for(int j=0;j<61;j++)
            dp[i][j] = -1;
}

long long solve(int w, int h){
    if(w == 0) return 1;

    long long& ret = dp[w][h];
    if(ret != -1) return ret;

    ret = 0;

    if(w > 0){
        ret += solve(w-1, h+1);
    }
    if(h > 0){
        ret += solve(w, h-1);
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while(1){
        int t;
        cin >> t;

        if(t==0) break;

        init();

        long long result = solve(t,0); 
        cout << result << "\n";

    }



}
