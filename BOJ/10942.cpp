#include<iostream>
#include<vector>

using namespace std;

int dp[2001][2001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        dp[i][i] = 1;
    }
    cin >> q;

    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(v[j] == v[j+i]){
                if(i == 1 || dp[j+1][j+i-1] == 1)
                    dp[j][j+i] = 1;
            }
        }
    }

    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";

    }

}
